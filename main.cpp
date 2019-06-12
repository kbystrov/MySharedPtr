#include <iostream>
#include <memory>
#include "MySharedPtr.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** @file */

int main() {

    std::cout << "Testing and comparing my shared ptr and std implementation" << std::endl << std::endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::cout << "Section 1: Testing shared_ptrs that points to null_ptr " << std::endl << std::endl;

    std::shared_ptr<int> std_null_ptr1;
    MySharedPtr<int> my_null_ptr1;

    std::cout << "std_null_ptr1.use_count() = " << std_null_ptr1.use_count() << std::endl;
    std::cout << "my_null_ptr1.use_count() = " << my_null_ptr1.use_count() << std::endl;
    std::cout << "std_null_ptr1.get() = " << std_null_ptr1.get() << std::endl;
    std::cout << "my_null_ptr1.get() = " << my_null_ptr1.get() << std::endl << std::endl;

    std::shared_ptr<int> std_null_ptr2(std_null_ptr1);
    MySharedPtr<int> my_null_ptr2(my_null_ptr1);

    std::cout << "std_null_ptr2.use_count() = " << std_null_ptr2.use_count() << std::endl;
    std::cout << "my_null_ptr2.use_count() = " << my_null_ptr2.use_count() << std::endl;
    std::cout << "std_null_ptr2.get() = " << std_null_ptr2.get() << std::endl;
    std::cout << "my_null_ptr2.get() = " << my_null_ptr2.get() << std::endl << std::endl;

    std::shared_ptr<int> std_null_ptr3(std_null_ptr2);
    MySharedPtr<int> my_null_ptr3(my_null_ptr2);

    std::cout << "std_null_ptr3.use_count() = " << std_null_ptr3.use_count() << std::endl;
    std::cout << "my_null_ptr3.use_count() = " << my_null_ptr3.use_count() << std::endl;
    std::cout << "std_null_ptr3.get() = " << std_null_ptr3.get() << std::endl;
    std::cout << "my_null_ptr3.get() = " << my_null_ptr3.get() << std::endl << std::endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::cout << "Section 2: Testing shared_ptrs " << std::endl << std::endl;

    int * int_val_std = new int(5);
    int * int_val_my = new int(10);

    std::shared_ptr<int> std_int_ptr1(int_val_std);
    MySharedPtr<int> my_int_ptr1(int_val_my);

    std::cout << "std_int_ptr1.use_count() = " << std_int_ptr1.use_count() << std::endl;
    std::cout << "my_int_ptr1.use_count() = " << my_int_ptr1.use_count() << std::endl;
    std::cout << "std_int_ptr1.get() = " << std_int_ptr1.get() << std::endl;
    std::cout << "my_int_ptr1.get() = " << my_int_ptr1.get() << std::endl;
    std::cout << "*std_int_ptr1 = " << *std_int_ptr1 << std::endl;
    std::cout << "*my_int_ptr1 = " << *my_int_ptr1 << std::endl << std::endl;

    std::shared_ptr<int> std_int_ptr2(std_int_ptr1);
    MySharedPtr<int> my_int_ptr2(my_int_ptr1);

    std::cout << "std_int_ptr2.use_count() = " << std_int_ptr2.use_count() << std::endl;
    std::cout << "my_int_ptr2.use_count() = " << my_int_ptr2.use_count() << std::endl;
    std::cout << "std_int_ptr2.get() = " << std_int_ptr2.get() << std::endl;
    std::cout << "my_int_ptr2.get() = " << my_int_ptr2.get() << std::endl;
    std::cout << "*std_int_ptr2 = " << *std_int_ptr2 << std::endl;
    std::cout << "*my_int_ptr2 = " << *my_int_ptr2 << std::endl << std::endl;

    std::shared_ptr<int> std_int_ptr3 = std_int_ptr2;
    MySharedPtr<int> my_int_ptr3 = my_int_ptr2;

    std::cout << "std_int_ptr3.use_count() = " << std_int_ptr3.use_count() << std::endl;
    std::cout << "my_int_ptr3.use_count() = " << my_int_ptr3.use_count() << std::endl;
    std::cout << "std_int_ptr3.get() = " << std_int_ptr3.get() << std::endl;
    std::cout << "my_int_ptr3.get() = " << my_int_ptr3.get() << std::endl;
    std::cout << "*std_int_ptr3 = " << *std_int_ptr3 << std::endl;
    std::cout << "*my_int_ptr3 = " << *my_int_ptr3 << std::endl << std::endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::cout << "Section 3: Copy assignment operator " << std::endl << std::endl;

    std::shared_ptr<int> std_int_ptr4(new int (9));
    MySharedPtr<int> my_int_ptr4(new int (18));

    std::cout << "std_int_ptr4.use_count() = " << std_int_ptr4.use_count() << std::endl;
    std::cout << "my_int_ptr4.use_count() = " << my_int_ptr4.use_count() << std::endl;
    std::cout << "std_int_ptr4.get() = " << std_int_ptr4.get() << std::endl;
    std::cout << "my_int_ptr4.get() = " << my_int_ptr4.get() << std::endl;
    std::cout << "*std_int_ptr4 = " << *std_int_ptr4 << std::endl;
    std::cout << "*my_int_ptr4 = " << *my_int_ptr4 << std::endl << std::endl;

    std::cout << "After copy assignemt operator with ptr3 " << std::endl << std::endl;

    std_int_ptr4 = std_int_ptr3;
    my_int_ptr4 = my_int_ptr3;

    std::cout << "std_int_ptr3.use_count() = " << std_int_ptr3.use_count() << std::endl;
    std::cout << "my_int_ptr3.use_count() = " << my_int_ptr3.use_count() << std::endl;
    std::cout << "std_int_ptr3.get() = " << std_int_ptr3.get() << std::endl;
    std::cout << "my_int_ptr3.get() = " << my_int_ptr3.get() << std::endl;
    std::cout << "*std_int_ptr3 = " << *std_int_ptr3 << std::endl;
    std::cout << "*my_int_ptr3 = " << *my_int_ptr3 << std::endl << std::endl;

    std::cout << "std_int_ptr4.use_count() = " << std_int_ptr4.use_count() << std::endl;
    std::cout << "my_int_ptr4.use_count() = " << my_int_ptr4.use_count() << std::endl;
    std::cout << "std_int_ptr4.get() = " << std_int_ptr4.get() << std::endl;
    std::cout << "my_int_ptr4.get() = " << my_int_ptr4.get() << std::endl;
    std::cout << "*std_int_ptr4 = " << *std_int_ptr4 << std::endl;
    std::cout << "*my_int_ptr4 = " << *my_int_ptr4 << std::endl << std::endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::cout << "Section 4: Swapping shared pointers" << std::endl << std::endl;

    std::shared_ptr<int> std_int_ptr5(new int (90));
    MySharedPtr<int> my_int_ptr5(new int (180));

    std::cout << "std_int_ptr5.use_count() = " << std_int_ptr5.use_count() << std::endl;
    std::cout << "my_int_ptr5.use_count() = " << my_int_ptr5.use_count() << std::endl;
    std::cout << "std_int_ptr5.get() = " << std_int_ptr5.get() << std::endl;
    std::cout << "my_int_ptr5.get() = " << my_int_ptr5.get() << std::endl;
    std::cout << "*std_int_ptr5 = " << *std_int_ptr5 << std::endl;
    std::cout << "*my_int_ptr5 = " << *my_int_ptr5 << std::endl << std::endl;

    std_int_ptr4.swap(std_int_ptr5);
    my_int_ptr4.swap(my_int_ptr5);

    std::cout << "After copy swapping with ptr4 " << std::endl << std::endl;

    std::cout << "std_int_ptr4.use_count() = " << std_int_ptr4.use_count() << std::endl;
    std::cout << "my_int_ptr4.use_count() = " << my_int_ptr4.use_count() << std::endl;
    std::cout << "std_int_ptr4.get() = " << std_int_ptr4.get() << std::endl;
    std::cout << "my_int_ptr4.get() = " << my_int_ptr4.get() << std::endl;
    std::cout << "*std_int_ptr4 = " << *std_int_ptr4 << std::endl;
    std::cout << "*my_int_ptr4 = " << *my_int_ptr4 << std::endl << std::endl;

    std::cout << "std_int_ptr5.use_count() = " << std_int_ptr5.use_count() << std::endl;
    std::cout << "my_int_ptr5.use_count() = " << my_int_ptr5.use_count() << std::endl;
    std::cout << "std_int_ptr5.get() = " << std_int_ptr5.get() << std::endl;
    std::cout << "my_int_ptr5.get() = " << my_int_ptr5.get() << std::endl;
    std::cout << "*std_int_ptr5 = " << *std_int_ptr5 << std::endl;
    std::cout << "*my_int_ptr5 = " << *my_int_ptr5 << std::endl << std::endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::cout << "Section 5: Reseting shared pointers" << std::endl << std::endl;

    std::cout << "std_int_ptr1.use_count() = " << std_int_ptr1.use_count() << std::endl;
    std::cout << "my_int_ptr1.use_count() = " << my_int_ptr1.use_count() << std::endl;
    std::cout << "std_int_ptr1.get() = " << std_int_ptr1.get() << std::endl;
    std::cout << "my_int_ptr1.get() = " << my_int_ptr1.get() << std::endl;
    std::cout << "*std_int_ptr1 = " << *std_int_ptr1 << std::endl;
    std::cout << "*my_int_ptr1 = " << *my_int_ptr1 << std::endl << std::endl;

    std::cout << "After reseting ptr5 with new pointer " << std::endl << std::endl;

    int * reset_int_std = new int(1000);
    int * reset_int_my = new int(2000);

    std_int_ptr5.reset(reset_int_std);
    my_int_ptr5.reset(reset_int_my);

    std::cout << "std_int_ptr5.use_count() = " << std_int_ptr5.use_count() << std::endl;
    std::cout << "my_int_ptr5.use_count() = " << my_int_ptr5.use_count() << std::endl;
    std::cout << "std_int_ptr5.get() = " << std_int_ptr5.get() << std::endl;
    std::cout << "my_int_ptr5.get() = " << my_int_ptr5.get() << std::endl;
    std::cout << "*std_int_ptr5 = " << *std_int_ptr5 << std::endl;
    std::cout << "*my_int_ptr5 = " << *my_int_ptr5 << std::endl << std::endl;

    std::cout << "std_int_ptr1.use_count() = " << std_int_ptr1.use_count() << std::endl;
    std::cout << "my_int_ptr1.use_count() = " << my_int_ptr1.use_count() << std::endl;
    std::cout << "std_int_ptr1.get() = " << std_int_ptr1.get() << std::endl;
    std::cout << "my_int_ptr1.get() = " << my_int_ptr1.get() << std::endl;
    std::cout << "*std_int_ptr1 = " << *std_int_ptr1 << std::endl;
    std::cout << "*my_int_ptr1 = " << *my_int_ptr1 << std::endl << std::endl;


    std::cout << "After reseting ptr1 with nothing " << std::endl << std::endl;

    std_int_ptr1.reset();
    my_int_ptr1.reset();

    std::cout << "std_int_ptr1.use_count() = " << std_int_ptr1.use_count() << std::endl;
    std::cout << "my_int_ptr1.use_count() = " << my_int_ptr1.use_count() << std::endl;
    std::cout << "std_int_ptr1.get() = " << std_int_ptr1.get() << std::endl;
    std::cout << "my_int_ptr1.get() = " << my_int_ptr1.get() << std::endl << std::endl;
    //std::cout << "*std_int_ptr1 = " << *std_int_ptr1 << std::endl;
    //std::cout << "*my_int_ptr1 = " << *my_int_ptr1 << std::endl << std::endl;

    std::cout << "std_int_ptr2.use_count() = " << std_int_ptr2.use_count() << std::endl;
    std::cout << "my_int_ptr2.use_count() = " << my_int_ptr2.use_count() << std::endl;
    std::cout << "std_int_ptr2.get() = " << std_int_ptr2.get() << std::endl;
    std::cout << "my_int_ptr2.get() = " << my_int_ptr2.get() << std::endl;
    std::cout << "*std_int_ptr2 = " << *std_int_ptr2 << std::endl;
    std::cout << "*my_int_ptr2 = " << *my_int_ptr2 << std::endl << std::endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    return 0;
}