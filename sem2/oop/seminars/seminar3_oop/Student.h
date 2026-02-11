//
// Created by Zagrean Sonia on 20.03.2025.
//

#ifndef STUDENT_H
#define STUDENT_H



class Student {
private:
    int age;
    char *name;
public:
    Student();
    Student(int age, char *name);
    Student(const Student &student); // ctor de copiere
    ~Student();
    Student &operator=(const Student &student);
    bool operator==(const Student &student);

    void setAge(int age);
    void setName(char *name);
    int getAge() const;
    char *getName() const;
};



#endif //STUDENT_H
