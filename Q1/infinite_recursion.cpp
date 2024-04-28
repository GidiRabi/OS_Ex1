#include <iostream>
void infinite_recursion() {
    infinite_recursion();
}
int main() {
    infinite_recursion();
    return 0;
}
