struct Planet {
  void move(double delta[3]);
  double coords[3];
};

int main() {
  double delta[3];

  Planet p;
  p.move(delta);
}