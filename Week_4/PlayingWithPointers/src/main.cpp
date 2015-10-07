#line 1 "PlayingWithPointers"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "PlayingWithPointers"
void setup() {

    int a = 1; // This is created on the stack.    
    std::cout << "a = " << a << std::endl;

    int* pA = &a; // Get the memory address of 'a'; 
    
    std::cout << "pA = " << pA << std::endl;
    std::cout << "*pA = " << *pA << std::endl;

    int b = 2;
    std::cout << "b = " << b << std::endl;
    
    pA = &b;
    std::cout << "*pA = " << *pA << std::endl;
    
    int* pHeapA = new int; // This is created on the "heap". 
    
    *pHeapA = 3;
    
    std::cout << "*pHeapA = " << *pHeapA << std::endl;

    pA = pHeapA;
    std::cout << "*pA = " << *pA << std::endl;
    
    delete pHeapA; // Frea the memory used on the "heap".
    
    // Now pA is a "dangling" pointer.  If you use it your program will crash.
    // std::cout << "*pA = " << *pA << std::endl;


    // std::shared_ptr<int> spInt = std::shared_ptr<int>(new int);
    std::shared_ptr<int> spInt = std::make_shared<int>();

    *spInt = 33;

    // Now pA is a "dangling" pointer.  If you use it your program will crash.
    std::cout << "*spInt = " << *spInt << std::endl;

}

void draw() {

	
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

