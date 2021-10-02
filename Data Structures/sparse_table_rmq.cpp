template <class T, class F = function <T(const T&, const T&)> >
class SparseTable {
  int _N;
  int _LOG;
  vector <T> _A;
  vector < vector <T> > ST;
  vector <int> Log;
  F func;

public :
  SparseTable() = default;

  template <class iter>
  SparseTable(iter _begin, iter _end, const F _func = less <T> ()) : func(_func) {
    _N = distance(_begin, _end);
        
    Log.assign(_N + 1, 0);
    for(int i = 2; i <= _N; ++i)
      Log[i] = Log[i >> 1] + 1;

    _LOG = Log[_N];

    _A.assign(_N + 1, 0);
    ST.assign(_N + 1, vector <T> (_LOG + 1, 0));

    __typeof(_begin) i = _begin;
    for(int j = 1; i != _end; ++i, ++j)
      _A[j] = *i;

    build();
  }

  void build() {
    for(int i = 1; i <= _N; ++i)
      ST[i][0] = i;

    for(int j = 1, k, d; j <= _LOG; ++j) {  // the two nested loops below have overall time complexity = O(n log n)
      k = (1 << j);
      d = (k >> 1);

      for(int i = 1; i + k - 1 <= _N; ++i) {
	T const & x = ST[i][j - 1];     // starting subarray at index = i     with length = 2^{j - 1}
	T const & y = ST[i + d][j - 1]; // starting subarray at index = i + d with length = 2^{j - 1}

	ST[i][j] = func(_A[x], _A[y]) ? x : y;
      }
    }
  }

  T query(int l, int r) { // this query is O(1)
    int d = r - l + 1;
    T const & x = ST[l][Log[d]];
    T const & y = ST[l + d - (1 << Log[d])][Log[d]];

    return func(_A[x], _A[y]) ? x : y;
  }
};

