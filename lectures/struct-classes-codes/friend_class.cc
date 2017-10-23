class B;

class A {

private:
  friend class B;
  int secret;
};

class B {
  int getSecret(A &a) { return a.secret; }
};
