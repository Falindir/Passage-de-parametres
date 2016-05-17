#include<iostream>

using namespace std;

class Simple {
    private :
        int var;

    public:
        Simple() {
            var = 42;
        }

        Simple(int n) {
            var = n;
        }

        ~Simple() {
        };

        virtual void setVar(int n){
            var = n;
        }

        virtual void print(){
            cout << "var : " << var << endl;
        }
};

class Content {
    private :
        Simple *s1;
        Simple **s2;

    public :

        Content() {
            s1 = new Simple();
            s2 = &s1;
        }

        ~Content() {
        }

        virtual void setS1(Simple *s){
            cout << "\nSet S : " << s << endl;
            cout << "Set &S : " << &s << endl;
            s1 = s;
            cout << "Set S1 : " << s1 << endl;
            cout << "Set &S1 : " << &s1 << endl;
        }

        virtual void setS2(Simple **s){
            cout << "\nSet S : " << s << endl;
            cout << "Set &S : " << &s << endl;
            s2 = s;
            cout << "Set S2 : " << s2 << endl;
            cout << "Set &S2 : " << &s2 << endl;
        }

        virtual void printS1(){
            cout << "\nS1 : " << s1 << endl;
            cout << "$S1 : " << &s1 << endl;
            s1->print();
            printS(s1);
            printSB(&s1);
        }

        virtual void printS2(){
            cout << "\nS2 : " << s2 << endl;
            cout << "$S2 : " << &s2 << endl;
            (*s2)->print();
            printS((*s2));
            printSB(s2);
        }

        virtual void printS(Simple *s) {
            cout << "Print S bis" << endl;
            cout << "Set S : " << s << endl;
            cout << "Set &S : " << &s << endl;
            s->print();
        }

        virtual void printSB(Simple **s) {
            cout << "Print S bis bis" << endl;
            cout << "Set S : " << s << endl;
            cout << "Set &S : " << &s << endl;
            printS(*s);
        }
};

int main(){

    Content *c1 = new Content();

    Content *c2 = new Content();

    Simple *s1 = new Simple(10);

    Simple *s2 = new Simple(20);

    Simple **s3 = new Simple *(new Simple(50));

    Simple **s4 = s3;

    cout << "\nS1 : " << s1 << endl;
    cout << "$S1 : " << &s1 << endl;
    s1->print();

    cout << "\nS2 : " << s2 << endl;
    cout << "&S2 : " << &s2 << endl;
    s2->print();

    cout << "\nS3 : " << s3 << endl;
    cout << "$S3 : " << &s3 << endl;
    (*s3)->print();

    cout << "\nS4 : " << s4 << endl;
    cout << "$S4 : " << &s4 << endl;
    (*s3)->print();

    c1->setS1(s1);
    c1->printS1();

    s1 = new Simple(1234);
    cout << "\nS1 : " << s1 << endl;
    cout << "$S1 : " << &s1 << endl;
    s1->print();

    c1->printS1();

    c1->setS2(&s2);
    c1->printS2();

    s1 = new Simple (11);
    s2 = new Simple (22);

    c1->printS1();
    c1->printS2();

    cout << "\nS1 : " << s1 << endl;
    cout << "$S1 : " << &s1 << endl;
    s1->print();


}
