/** Get Closest Common Waypoint
 * DATE : 5/12/2018
 * PROGRAMMER: Yu-Min Chen
 * MEMBER FUNCTION NAME:
 *    Node* getClosestCommonWaypoint(Node* A, Node* B)
 * PURPOSE:
 *    the following program that outputs the closest common waypoint from any given two path input, Node* A and Node* B.
 * PARAMETER:
 *    Node* A
 *    Node* B
 * RETURN VALUE:
 *    Node* (the closest common node)
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {}
};

class CIS14 {
public:
    Node* getClosestCommonWaypoint(Node* A, Node* B);
};

Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B) {
    Node *p1 = A;
    Node *p2 = B;

    if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2) {
                return p1;
            }

            if (p1 == NULL) {
                p1 = A;
            }
            if (p2 == NULL) {
                p2 = B;
            }
        }
        return p1;
    }

int main() {

    // a > b > c > d
    // e > f > g > c > d
    Node a(1), b(2), e(5), f(6), g(7), c(3), d(4);
    a.next=&b; b.next=&c;
    e.next=&f; f.next=&g, g.next=&c;
    c.next=&d; d.next=nullptr;

    CIS14 cis;
    Node* z = cis.getClosestCommonWaypoint(&a, &e);
    cout << (&c == z) << endl;

    return 0;
}


/** TEST RESULT
* input array: Node a, Node e
*              a > b > c > d
*              e > f > g > c > d
* output: c
*/
