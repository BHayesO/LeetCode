#include <iostream>

// Definición de la estructura del nodo de la lista enlazada
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* result_tail = result;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int out = sum % 10;

            result_tail->next = new ListNode(out);
            result_tail = result_tail->next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return result->next;
    }
};

int main() {
    // Crear las listas enlazadas de ejemplo
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Crear la solución y obtener el resultado
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Imprimir el resultado
    while (result != NULL) {
        std::cout << result->val;
        if (result->next != NULL) std::cout << " -> ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
