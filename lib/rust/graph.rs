
// Disjoint set

static mut PARENT: [i64; 10000] = [0i64; 10000];
static mut PARENT_RANK: [i64; 10000] = [0i64; 10000];

fn find_parent(n: i64) -> i64 {
  unsafe {
    if PARENT[n as usize] != n { PARENT[n as usize] = find_parent(PARENT[n as usize]) }
    return PARENT[n as usize];
  }
}

fn merge_sets(a: i64, b: i64) {
  unsafe {
    let parentA = find_parent(a) as usize;
    let parentB = find_parent(b) as usize;

    if parentA == parentB {return};
    
    if PARENT_RANK[parentA] > PARENT_RANK[parentB] {
      PARENT[parentB] = parentA as i64;
      PARENT_RANK[parentA] += PARENT_RANK[parentB];
    } else {
      PARENT[parentA] = parentB as i64;
      PARENT_RANK[parentB] += PARENT_RANK[parentA];
    }
  }
}


