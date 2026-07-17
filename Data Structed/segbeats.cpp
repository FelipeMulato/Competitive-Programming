const ll INF = 1e18;
struct Node {
	ll mx = -INF, mx2 = -INF, cx = 0;
	ll mn = INF, mn2 = INF, cn = 0;
	ll sum = 0, lz_add = 0;
};
 
struct STBeats {
	int n; vector<Node> t;
	STBeats(int n) : n(n), t(4 * n) {}
	void pull(int i) {
		int l = 2 * i, r = 2 * i + 1;
		t[i].sum = t[l].sum + t[r].sum;
		if (t[l].mx > t[r].mx) { t[i].mx = t[l].mx; t[i].cx = t[l].cx; t[i].mx2 = max(t[l].mx2, t[r].mx); }
		else if (t[l].mx < t[r].mx) { t[i].mx = t[r].mx; t[i].cx = t[r].cx; t[i].mx2 = max(t[l].mx, t[r].mx2); }
		else { t[i].mx = t[l].mx; t[i].cx = t[l].cx + t[r].cx; t[i].mx2 = max(t[l].mx2, t[r].mx2); }
 
		if (t[l].mn < t[r].mn) { t[i].mn = t[l].mn; t[i].cn = t[l].cn; t[i].mn2 = min(t[l].mn2, t[r].mn); }
		else if (t[l].mn > t[r].mn) { t[i].mn = t[r].mn; t[i].cn = t[r].cn; t[i].mn2 = min(t[l].mn, t[r].mn2); }
		else { t[i].mn = t[l].mn; t[i].cn = t[l].cn + t[r].cn; t[i].mn2 = min(t[l].mn2, t[r].mn2); }
	}
	void apply_add(int i, int l, int r, ll v) {
		t[i].sum += v * (r - l + 1);
		t[i].mx += v; if (t[i].mx2 != -INF) t[i].mx2 += v;
		t[i].mn += v; if (t[i].mn2 != INF) t[i].mn2 += v;
		t[i].lz_add += v;
	}
	void apply_min(int i, ll v) {
		if (t[i].mx <= v) return;
		t[i].sum -= t[i].cx * (t[i].mx - v);
		if (t[i].mn == t[i].mx) t[i].mn = v;
		else if (t[i].mn2 == t[i].mx) t[i].mn2 = v;
		t[i].mx = v;
	}
	void apply_max(int i, ll v) {
		if (t[i].mn >= v) return;
		t[i].sum += t[i].cn * (v - t[i].mn);
		if (t[i].mx == t[i].mn) t[i].mx = v;
		else if (t[i].mx2 == t[i].mn) t[i].mx2 = v;
		t[i].mn = v;
	}
	void push(int i, int l, int r) {
		int m = (l + r) / 2;
		if (t[i].lz_add) { apply_add(2 * i, l, m, t[i].lz_add); apply_add(2 * i + 1, m + 1, r, t[i].lz_add); t[i].lz_add = 0; }
		apply_min(2 * i, t[i].mx); apply_min(2 * i + 1, t[i].mx);
		apply_max(2 * i, t[i].mn); apply_max(2 * i + 1, t[i].mn);
	}
	void build(int i, int l, int r, const vector<ll>& a) {
		if (l == r) { t[i] = {a[l], -INF, 1, a[l], INF, 1, a[l], 0}; return; }
		int m = (l + r) / 2; build(2 * i, l, m, a); build(2 * i + 1, m + 1, r, a); pull(i);
	}
	void update_min(int i, int l, int r, int ql, int qr, ll x) {
		if (r < ql || qr < l || t[i].mx<=x) return;
		if (ql <= l && r <= qr && t[i].mx2<x) {
			apply_min(i,x); 
            return;
		}
		push(i, l, r); int m = (l + r) / 2;
		update_min(2 * i, l, m, ql, qr, x); update_min(2 * i + 1, m + 1, r, ql, qr, x); pull(i);
	}
    void update_add(int i, int l, int r, int ql, int qr, ll v) {
		if (r < ql || qr < l) return;
		if (ql <= l && r <= qr) { apply_add(i, l, r, v); return; }
		push(i, l, r); int m = (l + r) / 2;
		update_add(2 * i, l, m, ql, qr, v); update_add(2 * i + 1, m + 1, r, ql, qr, v); pull(i);
	}
	ll query_sum(int i, int l, int r, int ql, int qr) {
		if (r < ql || qr < l) return 0;
		if (ql <= l && r <= qr) return t[i].sum;
		push(i, l, r); int m = (l + r) / 2;
		return query_sum(2 * i, l, m, ql, qr) + query_sum(2 * i + 1, m + 1, r, ql, qr);
	}
};


///chamar as funções com i=1, interva de [0,n-1] e o vetor a com os valores iniciais