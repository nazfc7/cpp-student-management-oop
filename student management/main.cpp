#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Student {
public:
string name;
string surname; double grade;
}; 
vector<Student> students;

void addStudent(){ 
  Student s; 
  cout << "Ad: "; 
  cin >> s.name; 
  cout << "Soyad: "; 
  cin >> s.surname;
  cout << "Not: "; 
  cin >> s.grade; 
  students.push_back(s); 
  cout << "Ogrenci eklendi.\n";
} 

void deleteStudent() { 
  string name; 
  cout << "Silinecek ogrencinin adi: "; 
  cin >> name; 
  auto it = remove_if(students.begin(), students.end(), [name](Student s) { 
    return s.name == name; 
  }); 
  
  if (it != students.end()) { 
    students.erase(it, students.end());
    cout << "Ogrenci silindi.\n"; 
  } 
  
  else { 
    cout << "Ogrenci bulunamadi.\n"; 
  }
} 
void listStudents() 
{
  if (students.empty()) {
  cout << "Hic ogrenci yok.\n"; return; 
  } 
  for (const auto& s : students)
    { 
      cout << s.name << " " << s.surname << " - Not: " << s.grade << endl;
    } 
} 
void calculateAverage() { 
  if (students.empty()) { 
    cout << "Ogrenci yok.\n"; return; 
  } 
  
  double total = 0; 
  
  for (const auto& s : students) {
    
    total += s.grade; 
  } 
  
  cout << "Sinif Ortalamasi: " << total / students.size() << endl;
} 
int main() {
int choice; bool running = true; while (running) { 
  cout << "\n=== Ogrenci Yonetim Sistemi ===\n"; 
  cout << "1) Ogrenci Ekle\n"; 
  cout << "2) Ogrenci Sil\n"; 
  cout << "3) Listele\n"; 
  cout << "4) Ortalama Hesapla\n"; 
  cout << "5) Cikis\n"; 
  cout << "Seciminiz: "; 
  cin >> choice; switch (choice) {
    case 1: addStudent();
      break; 
    case 2: deleteStudent();
      break;
    case 3: listStudents();
      break; 
    case 4: calculateAverage(); 
      break; 
    case 5: running = false; 
      break; 
    default:
      cout << "Gecersiz secim!\n"; 
  } 
}
