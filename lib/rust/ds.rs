#[derive(Copy, Clone, Eq, PartialEq, Debug)]
struct Data(i64, i64);

impl Ord for Data {
  fn cmp(&self, other: &Data) -> Ordering {
    match self.0.cmp(&other.0).reverse() {
      Ordering::Equal => self.1.cmp(&other.1),
      other => other
    }
  }
}

impl PartialOrd for Data {
  fn partial_cmp(&self, other: &Data) -> Option<Ordering> { Some(self.cmp(other)) }
}

