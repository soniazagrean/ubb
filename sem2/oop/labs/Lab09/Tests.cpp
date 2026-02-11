#include <iostream>
#include <fstream>
#include "Product.h"
#include "Repository.h"
#include "Service.h"
#include "RepoFile.h"
#include "assert.h"
#include <string>

using namespace std;

void testProduct(){
  Product p1(12, "ciocolata", 12.2);
  Product p2(23, "bomboane", 20.1);
  Product p3(1, "biscuiti", 13.8);
  Product p4(1, "biscuiti", 13.8);
  assert(p1.getCode() == 12);
  assert(p2.getName() == "bomboane");
  assert(p3.getPrice() == 13.8);
  assert(p3 == p4);
}

void testRepo(){
  Repository r;
  Product p1(12, "ciocolata", 12.2);
  Product p2(23, "bomboane", 20.1);
  Product p3(1, "biscuiti", 13.8);
  Product p4(1, "biscuiti", 13.8);
  r.addItem(p1);
  r.addItem(p2);
  r.addItem(p3);
  r.addItem(p4);
  vector<Product> v = r.getAll();
  assert(v[0] == p1);
  assert(v[1] == p2);
  assert(v[2] == p3);
  assert(v[3] == p4);
  r.removeItem(p4);
  //std::cout << r.getSize();
  for (auto &i: r.getAll())
  assert(r.getSize() == 2);
  // std::cout << r.getSize();
}

void testService(){
  Repository r;
  Service s(r);
  s.add(12, "ciocolata", 12.2);
  s.add(23, "bomboane", 20.1);
  s.add(1, "biscuiti", 13.8);
  s.add(1, "biscuiti", 13.8);
  assert(s.getSizeOf() == 4);
  s.remove(1, "biscuiti", 13.8);
  assert(s.getSizeOf() == 2);


  s.add(10, "cafea", 4.5);
  s.add(20, "praji", 3.0);

  std::vector<Money> change1 = s.buyProduct(10, 5.5);
  int totalChange1 = 0;
  for (auto& m : change1)
    totalChange1 += m.val * m.freq;
  assert(totalChange1 == 100); // correct

  std::vector<Money> change2 = s.buyProduct(20, 2.0);
  assert(change2.empty()); // not enough

  std::vector<Money> change3 = s.buyProduct(99, 5.0);
  assert(change3.empty()); // not found

  std::vector<Money> change4 = s.buyProduct(20, 3.5);
  if (!change4.empty()) {
    int totalChange4 = 0;
    for (auto& m : change4) totalChange4 += m.val * m.freq;
    assert(totalChange4 == 50 || totalChange4 < 50);  // not available
  }
}



void testRepoFile() {
  std::string testFile = "products.txt";
  std::ofstream fout(testFile);
  fout << "12 ciocolata 33.2\n";
  fout << "20 apa 5.5\n";
  fout.close();
  RepoFile repo(testFile);

  //std::cout << "size: " << repo.getSize() << std::endl;
  assert(repo.getSize() == 2);

  assert(repo.getAll()[0] == Product(12, "ciocolata", 33.2));
  assert(repo.getAll()[1] == Product(20, "apa", 5.5));

  Product p3(103, "prajitura", 3.2);
  repo.addItem(p3);
  assert(repo.getSize() == 3);

  repo.removeItem(Product(12, "ciocolata", 33.2));
  assert(repo.getSize() == 2);
}
