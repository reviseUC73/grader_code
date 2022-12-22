#include <iostream>

using namespace std;

struct Cookie {
  int uid;
  Cookie *next;

  Cookie(int c_uid, Cookie *c_next = 0) : uid(c_uid), next(c_next) {}
};

void print_cookie(Cookie *dummy_cookie) {
  dummy_cookie = dummy_cookie->next;
  while (dummy_cookie != nullptr) {
    cout << dummy_cookie->uid << endl;
    dummy_cookie = dummy_cookie->next;
  };
}

void add_cookie(Cookie *cookie, int k, int uid) {
  Cookie *focused_cookie = cookie->next;
  Cookie *previous_cookie = cookie;
  for (int i = 0; i < k; i++) {
    if (focused_cookie == nullptr) {
      break;
    }

    previous_cookie = focused_cookie;
    focused_cookie = focused_cookie->next;
  }
  Cookie *new_cookie = new Cookie(uid, focused_cookie);
  previous_cookie->next = new_cookie;
}

void eat_cookie(Cookie *cookie, int k) {
  Cookie *focused_cookie = cookie->next;
  Cookie *previous_cookie = cookie;
  if (focused_cookie == nullptr) {
    return;
  }
  for (int i = 1; i < k; i++) {
    if (focused_cookie == nullptr) {
      break;
    }
    previous_cookie = focused_cookie;
    focused_cookie = focused_cookie->next;
  }
  if (focused_cookie == nullptr) {
    return;
  }
  previous_cookie->next = focused_cookie->next;
  delete focused_cookie;
}

int main() {
  int t;
  cin >> t;
  Cookie *dummy_cookie = new Cookie(-1);
  for (int i = 0; i < t; i++) {
    int l;
    cin >> l;
    if (l == 1) {
      // Add Operation
      int k, x;
      cin >> k >> x;
      add_cookie(dummy_cookie, k, x);
    print_cookie(dummy_cookie);

    } else {
      // Eat Operation
      int k;
      cin >> k;
      eat_cookie(dummy_cookie, k);
     print_cookie(dummy_cookie);

    }
  }
  cout<<endl;
  print_cookie(dummy_cookie);
  return 0;
}