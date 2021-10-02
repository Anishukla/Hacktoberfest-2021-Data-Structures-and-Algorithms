const int N = 5e5 + 9, M = 1e3 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int BLK = 256;

int n, q, a[N], type, x, y, z;
vector <int> bs[M];

int query(int l, int r, int val) {
  int cur_l = l / BLK;
  int cur_r = r / BLK;
  int ans = 0;

  if(cur_l == cur_r) {
    for (int i = l; i <= r; ++i)
      ans += (a[i] >= val);
  } else {
    for(int i = l, _end = (cur_l + 1) * BLK; i < _end; ++i)
      ans += (a[i] >= val);
    for(int i = cur_l + 1; i <= cur_r - 1; ++i)
      ans += bs[i].end() - lower_bound(bs[i].begin(), bs[i].end(), val);
    for(int i = cur_r * BLK; i <= r; ++i)
      ans += (a[i] >= val);
  }
  return ans;
}

void build() {
  for(int i = 0; i < n; ++i)
    bs[i / BLK].emplace_back(a[i]);

  for(int i = 0; i < M; ++i)
    sort(bs[i].begin(), bs[i].end());
}

void update(int id, int delta) {
  int pos = lower_bound(bs[id / BLK].begin(), bs[id / BLK].end(), a[id]) - bs[id / BLK].begin();
  bs[id / BLK][pos] = delta;
  sort(bs[id / BLK].begin(), bs[id / BLK].end());
  a[id] = delta;
}

void Solve() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];

  build();
  cin >> q;
  while(q--) {
    cin >> type >> x >> y;
    if(type == 0) {
      cin >> z;
      cout << query(x, y, z) << endl;
    }
    else
      update(x, y);
  }
}

