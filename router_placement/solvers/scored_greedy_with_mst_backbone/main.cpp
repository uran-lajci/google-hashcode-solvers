#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define tget(X,id) get<id>(X)

#define MAXN 1005

string FILE_IN, FILE_OUT;

int WEIGHT_COVER = 1, WEIGHT_WALLADJ = 1, WEIGHT_COVER_SQ = 0, WEIGHT_WALLADJ_SQ = 0, WEIGHT_BACKCOST = 0, WEIGHT_COVADJ = 0;

int H, W, R;
long long C_B, C_R, B, BB;
char PLANE[MAXN][MAXN];
char PLANE_TMP[MAXN][MAXN];
int PLANE_WALL[MAXN][MAXN];
bool BACKBONE[MAXN][MAXN];
bool BACKBONE_TMP[MAXN][MAXN];
bool BACKBONE_TMP2[MAXN][MAXN];
int BACKBONE_COST[MAXN][MAXN];
bool COVERED[MAXN][MAXN];
bool ROUTER[MAXN][MAXN];
bool RECT_COVERED[MAXN][MAXN];
ii RECT_CHAMPION[MAXN][MAXN];

int backinit[2];

int u_P[MAXN*MAXN], u_R[MAXN*MAXN];
void u_init(int sz){
    for (int i = 0; i < sz; i++) u_P[i] = i, u_R[i] = 0;
}
int u_parent(int i){
    return (u_P[i] == i ? i : u_P[i] = u_parent(u_P[i]));
}
int u_same(int a, int b){
    return u_parent(a) == u_parent(b);
}
void u_join(int a, int b){
    a = u_parent(a);
    b = u_parent(b);
    if (u_R[a] > u_R[b])
        u_P[b] = a;
    else {
        u_P[a] = b;
        if (u_R[a] == u_R[b]) u_R[b]++;
    }
}
int BB_MAX_DIST = 1000;

int theres_a_wall(int a, int b, int c, int d){
    return PLANE_WALL[c][d]-(a>0?PLANE_WALL[a-1][d]:0)-(b>0?PLANE_WALL[c][b-1]:0)+(a>0&&b>0?PLANE_WALL[a-1][b-1]:0);
}

void quick_calc_backcost(queue<ii> &q){
    while (!q.empty()){
        auto x = q.front(); q.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (x.ff+i >= 0 && x.ff+i < H && x.ss+j >= 0 && x.ss+j < W){
                    if (BACKBONE_COST[x.ff+i][x.ss+j] > BACKBONE_COST[x.ff][x.ss] + C_B)
                        BACKBONE_COST[x.ff+i][x.ss+j] = min(BACKBONE_COST[x.ff][x.ss] + C_B, B+1),
                        q.push(mp(x.ff+i,x.ss+j));
                }
    }
}
void calc_backcost(){
    queue<ii> q;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (BACKBONE[i][j])
                q.push(mp(i,j)), BACKBONE_COST[i][j] = 0;
            else
                BACKBONE_COST[i][j] = B+1;
        }
    quick_calc_backcost(q);
    
    BB_MAX_DIST = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            BB_MAX_DIST = max(BB_MAX_DIST, BACKBONE_COST[i][j]);
}

ll SCORES[MAXN][MAXN];
#define SCORES_INV (-B-B)

pair<ll, ii> calc_scores(){
    ll best = SCORES_INV;
    ii bester = mp(0,0);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (BB-(BACKBONE_COST[i][j]*C_B+C_R) < 0) continue;
            if (ROUTER[i][j] || PLANE[i][j] == '#') continue;
            if (SCORES[i][j] == SCORES_INV){
                int cover = 0, wall_adj = 0, cov_adj = 0;
                for (int a = -R; a <= R; a++)
                    for (int b = -R; b <= R; b++)
                        if (i+a >= 0 && i+a < H && j+b >= 0 && j+b < W){
                            if (COVERED[i+a][j+b] || PLANE[i+a][j+b] != '.') continue;
                            if (!theres_a_wall(min(i+a,i),min(j+b,j),max(i+a,i),max(j+b,j))){
                                cover++;
                                for (int aa = -1; aa <= 1; aa++) for (int bb = -1; bb <= 1; bb++)
                                    if (i+a+aa >= 0 && i+a+aa < H && j+b+bb >= 0 && j+b+bb < W){
                                        if (PLANE[i+a+aa][j+b+bb] == '#')
                                            wall_adj++;
                                        else if (COVERED[i+a+aa][j+b+bb] && max(abs(i+a+aa-i),abs(j+b+bb-j)) == R+1)
                                            cov_adj++;
                                    }
                            }
                        }
                ll score = WEIGHT_COVER * cover + WEIGHT_WALLADJ * wall_adj + WEIGHT_COVER_SQ * cover * cover + WEIGHT_WALLADJ_SQ * wall_adj * wall_adj + WEIGHT_BACKCOST * BACKBONE_COST[i][j] + WEIGHT_COVADJ * cov_adj;
                SCORES[i][j] = score;
            }
            if (SCORES[i][j] > best){
                bester = mp(i,j);
                best = SCORES[i][j];
            }
        }
    return mp(best, bester);
}

void fix_backbone(){
    vii pts;
    
    memset(BACKBONE, 0, sizeof BACKBONE);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (!ROUTER[i][j]) continue;
            pts.pb(mp(i,j));
            BACKBONE[i][j] = 1;
    }
    pts.pb(mp(backinit[0], backinit[1]));
    BACKBONE[backinit[0]][backinit[1]] = 1;
    
    //~ cout<<"MST:Pts="<<pts.size()<<endl;
    vector<pair<int, ii> > edges;
    for (unsigned int i = 0; i < pts.size(); i++)
        for (unsigned int j = i+1; j < pts.size(); j++)
            edges.pb(mp(max(abs(pts[i].ff-pts[j].ff),abs(pts[i].ss-pts[j].ss)),mp(i,j)));
    sort(edges.begin(), edges.end());
    //~ cout<<"MST:Edges="<<edges.size()<<endl;
    //~ cout<<"MST"<<endl;
    u_init(pts.size()+5);
    int cnt = pts.size(), i = 0, a, b;
    while (cnt > 1){
        //~ cout<<cnt<<endl;
        auto x = edges[i++];
        if (u_same(x.ss.ff, x.ss.ss)) continue;
        u_join(x.ss.ff, x.ss.ss);
        cnt--;
        //~ BACKBONE[pts[x.ss.ff].ff][pts[x.ss.ff].ss] = 0;
        ii x1, x2 = mp(-1,-1);
        queue<ii> q;
        // Flood fill
        memset(BACKBONE_TMP2, 0, sizeof BACKBONE_TMP2);
        q.push(pts[x.ss.ss]);
        BACKBONE_TMP2[pts[x.ss.ss].ff][pts[x.ss.ss].ss] = 1;
        int zcnt = 0;
        while (!q.empty()){
            x1 = q.front();
            q.pop();
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                    if (x1.ff+i >= 0 && x1.ff+i < H && x1.ss+j >= 0 && x1.ss+j < W){
                        if (BACKBONE[x1.ff+i][x1.ss+j] && BACKBONE_TMP2[x1.ff+i][x1.ss+j] == 0){
                            BACKBONE_TMP2[x1.ff+i][x1.ss+j] = 1;
                            q.push(mp(x1.ff+i,x1.ss+j));
                            zcnt++;
                        }
                    }
        }
        //~ cout<<"zcnt:"<<zcnt<<endl;
        // BFS
        memset(BACKBONE_TMP, 0, sizeof BACKBONE_TMP);
        q.push(pts[x.ss.ff]);
        BACKBONE_TMP[pts[x.ss.ff].ff][pts[x.ss.ff].ss] = 1;
        while (!q.empty()){
            x1 = q.front();
            //~ cout<<"@"<<x1.ff<<","<<x1.ss<<endl;
            q.pop();
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                    if (x1.ff+i >= 0 && x1.ff+i < H && x1.ss+j >= 0 && x1.ss+j < W){
                        if (!BACKBONE_TMP[x1.ff+i][x1.ss+j]){
                            if (BACKBONE_TMP2[x1.ff+i][x1.ss+j]){
                                x2 = mp(x1.ff+i, x1.ss+j);
                                break;
                            }
                            BACKBONE_TMP[x1.ff+i][x1.ss+j] = 1;
                            q.push(mp(x1.ff+i,x1.ss+j));
                        }
                    }
            if (x2.ff != -1)
                break;
        }
        //~ cout<<"x2:"<<x2.ff<<","<<x2.ss<<endl;
        a = pts[x.ss.ff].ff, b = pts[x.ss.ff].ss;
        //~ queue<ii> new_back;
        //~ x2 = pts[x.ss.ss];
        while (mp(a,b) != x2){
            //~ new_back.push(mp(a,b));
            BACKBONE[a][b] = 1;
            BACKBONE_COST[a][b] = 0;
            if (a > x2.ff) a--;
            if (a < x2.ff) a++;
            if (b > x2.ss) b--;
            if (b < x2.ss) b++;
        }
    }
    int backcnt = -1, rtrcnt = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (!ROUTER[i][j]) continue;
            rtrcnt++;
        }
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (BACKBONE[i][j]) backcnt++;
    BB = B - (rtrcnt * C_R + backcnt * C_B);
    calc_backcost();
}
int main(int argc, char *argv[]){
    //~ int seed = time(NULL);
    //~ srand(seed);
    
    // Input stuff, you should ignore this
    int INPUT_FILE = -1;
    if (argc == 1){
        cerr<<"No input specified, using input 1.\n FIY, you should run "<<argv[0]<<" [(1|2|3|4|input_name) [param1 [param2 ... ]]]"<<endl;
        INPUT_FILE = 1;
    }
    if (argc >= 2){
        int z = atoi(argv[1]);
        if (z == 0 && strlen(argv[1]) == 1){
            cerr<<"You specified 0 as first arg, but input numbers are from 1 to 4.. Idiot.\nUsing input 1, just for this time"<<endl;
            INPUT_FILE = 1;
        } else if (z == 0)
            INPUT_FILE = 0;
        else {
            if (z < 1 || z > 4){
                cerr<<"Your input file was not in [1,4], using 1 because I'm merciful"<<endl;
                INPUT_FILE = 1;
            } else
                INPUT_FILE = z;
        }
    }
    switch (INPUT_FILE){
        case 1:
            FILE_IN = "charleston_road.in";
            FILE_OUT = "charleston_road.out";
            break;
        case 2:
            FILE_IN = "lets_go_higher.in";
            FILE_OUT = "lets_go_higher.out";
            break;
        case 3:
            FILE_IN = "opera.in";
            FILE_OUT = "opera.out";
            break;
        case 4:
            FILE_IN = "rue_de_londres.in";
            FILE_OUT = "rue_de_londres.out";
            break;
        case 0:
            FILE_IN = string(argv[1]);
            FILE_OUT = FILE_IN + ".out";
            break;
        default:
            cerr<<"Look, i dunno how you get there, ask someone.";
            return 1;
    }
    // Parameter stuff, for tuning
    //~ int param = 0;
    if (argc >= 3) WEIGHT_COVER = atoi(argv[2]);
    if (argc >= 4) WEIGHT_WALLADJ = atoi(argv[3]);
    if (argc >= 5) WEIGHT_COVER_SQ= atoi(argv[4]);
    if (argc >= 6) WEIGHT_WALLADJ_SQ = atoi(argv[5]);
    if (argc >= 7) WEIGHT_BACKCOST = atoi(argv[6]);
    if (argc >= 8) WEIGHT_COVADJ = atoi(argv[7]);
    
    //~ cout<<"Got parameter "<<param<<endl;
    
    // Actual code
    freopen(FILE_IN.c_str(),"r",stdin);
    
    int a,b,c;
    
    scanf("%d%d%d", &H, &W, &R);
    scanf("%d%d%d", &a, &b, &c); // just trust me
    C_B = a, C_R = b, B = c;
    scanf("%d%d", &backinit[0], &backinit[1]);
    BACKBONE[backinit[0]][backinit[1]] = 1;
    for (int i = 0; i < H; i++)
        scanf("%s", PLANE[i]);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            PLANE_WALL[i][j] = (PLANE[i][j]=='#')+(i>0?PLANE_WALL[i-1][j]:0)+(j>0?PLANE_WALL[i][j-1]:0)-(i>0&&j>0?PLANE_WALL[i-1][j-1]:0);
            SCORES[i][j] = SCORES_INV;
        }
    
    BB = B;
    //~ for (int i = 0; i < H; i++){ for (int j = 0; j < W; j++) cout<<BACKBONE[i][j]; cout<<endl;}
    //~ for (int i = 0; i < H; i++){ for (int j = 0; j < W; j++) cout<<BACKBONE_COST[i][j]<<"|"; cout<<endl;}
    
    int phase = 0, rtr = 0;
    while (true){
        auto x = calc_scores();
        if (x.ff <= 0){
            if (phase == 0){
                phase = 2;
                fix_backbone();
                continue;
            } else
                break;
        }
        if (phase == 2) phase = 0;
        //~ cout<<BB<<"\t"<<x.ff<<":"<<x.ss.ff<<","<<x.ss.ss<<"\tP"<<phase<<endl;
        //~ if (BACKBONE_COST[x.ss.ff][x.ss.ss]*C_B+C_R <= 0) break;
        ROUTER[x.ss.ff][x.ss.ss] = 1;
        if (phase == 0){
            BB -= max(W,H)*C_B + C_R;
            if (BB < 0)
                phase = 1;
        }
        if (phase == 1){
            //~ cout<<"\tFixed BB"<<endl;
            fix_backbone();
            if (BB < 0){
                ROUTER[x.ss.ff][x.ss.ss] = 0;
                fix_backbone();
                break;
            } else
                phase = 0;
        }
        for (int a = -R; a <= R; a++)
            for (int b = -R; b <= R; b++)
                if (x.ss.ff+a >= 0 && x.ss.ff+a < H && x.ss.ss+b >= 0 && x.ss.ss+b < W){
                    SCORES[x.ss.ff+a][x.ss.ss+b] = SCORES_INV;
                    if (COVERED[x.ss.ff+a][x.ss.ss+b] || PLANE[x.ss.ff+a][x.ss.ss+b] != '.') continue;
                    if (!theres_a_wall(min(x.ss.ff+a,x.ss.ff),min(x.ss.ss+b,x.ss.ss),max(x.ss.ff+a,x.ss.ff),max(x.ss.ss+b,x.ss.ss))){
                        COVERED[x.ss.ff+a][x.ss.ss+b] = 1;
                    }
                }
        int LLL = R*2+1;
        for (int a = -LLL; a <= LLL; a++)
            for (int b = -LLL; b <= LLL; b++)
                if (x.ss.ff+a >= 0 && x.ss.ff+a < H && x.ss.ss+b >= 0 && x.ss.ss+b < W)
                    SCORES[x.ss.ff+a][x.ss.ss+b] = SCORES_INV;
        rtr++;
        cout<<"BB="<<BB<<" RTR="<<rtr<<endl;
        //~ break;
    }
    fix_backbone();
    //~ vii pts;
    //~ for (int i = 0; i < H; i++)
        //~ for (int j = 0; j < W; j++)
            //~ if (mp(i,j)==mp(backinit[0],backinit[1]) || ROUTER[i][j])
                //~ pts.pb(mp(i,j));
    //~ vector<pair<int, ii> > edge;
    //~ for (int i = 0; i < pts.size(); i++)
        //~ for (int j = i+1; j < pts.size(); j++)
            //~ edge.pb(mp(max(abs(pts[i].ff-pts[j].ff), abs(pts[i].ss-pts[j].ss)),mp(i,j)));
    //~ sort(edge.begin(), edge.end());
    
    //~ fix_backbone();
    
    ll ans = 0;
    int backcnt = -1, rtrcnt = 0;
    
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (COVERED[i][j]) ans += 1000;
            if (ROUTER[i][j]) rtrcnt++;
    }
    
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (BACKBONE[i][j]) backcnt++;
            
    //~ for (int i = 0; i < H; i++){
        //~ for (int j = 0; j < W; j++)
            //~ cout<<BACKBONE[i][j];
        //~ cout<<endl;
    //~ }
    BACKBONE[backinit[0]][backinit[1]] = 0;
    
    cout<<"Score(Cov*1000):"<<ans<<endl;
    cout<<"Router:"<<rtrcnt<<endl;
    cout<<"Backbone:"<<backcnt<<endl;
    cout<<"RemainingBudget:"<<B - (rtrcnt * C_R + backcnt * C_B)<<endl;
    if (B - (rtrcnt * C_R + backcnt * C_B) < 0){
        cerr<<"Dafaq B is negative"<<endl;
        exit(0);
    }
    cout<<FILE_OUT<<" "<<ans + (B - (rtrcnt * C_R + backcnt * C_B))<<endl;
    
    //~ cout<<"Now i'll print the score (a+param**2) and the fileout"<<endl;
    //~ cout<<FILE_OUT<<" "<<a+param*param<<endl;
    
    freopen("debug.txt","w",stdout);
    memcpy(PLANE_TMP, PLANE, sizeof PLANE);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++){
            if (BACKBONE[i][j]) PLANE_TMP[i][j] = '*';
            if (ROUTER[i][j]) PLANE_TMP[i][j] = 'O';
            if (ROUTER[i][j] && BACKBONE[i][j]) PLANE_TMP[i][j] = 'G';
        }
    PLANE_TMP[backinit[0]][backinit[1]] = 'X';
    for (int i = 0; i < H; i++)
        cout<<PLANE_TMP[i]<<endl;
    
    // Solution printing
    freopen(FILE_OUT.c_str(),"w",stdout);
    printf("%d\n", backcnt);
    queue<ii> q;
    q.push(mp(backinit[0],backinit[1]));
    while (!q.empty()){
        auto x = q.front(); q.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (x.ff+i >= 0 && x.ff+i < H && x.ss+j >= 0 && x.ss+j < W){
                    if (BACKBONE[x.ff+i][x.ss+j])
                        BACKBONE[x.ff+i][x.ss+j] = 0,
                        printf("%d %d\n", x.ff+i, x.ss+j),
                        q.push(mp(x.ff+i,x.ss+j));
                }
    }
    printf("%d\n", rtrcnt);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (ROUTER[i][j])
                printf("%d %d\n", i, j);
    return 0;
}
