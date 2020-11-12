/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if((poly1 == NULL) && (poly2 == NULL))
            return NULL;
        if((poly1 == NULL) && (poly2 != NULL))
            return poly2;
        if((poly1 != NULL) && (poly2 == NULL))
            return poly1;
        PolyNode* dummy = new PolyNode(0,0);
        PolyNode* current = dummy;
        while((poly1!=NULL) || (poly2!=NULL))
        {
            if((poly2 == NULL) || ((poly1!=NULL) && (poly1->power>poly2->power)))
            {
                current->next = new PolyNode(poly1->coefficient,poly1->power);
                //cout<<current->next->power<<" "<<current->next->coefficient<<endl;
                poly1=poly1->next;
                current=current->next;
            }
            else if((poly1 == NULL) || ((poly2!=NULL) && (poly2->power>poly1->power)))
            {
                current->next = new PolyNode(poly2->coefficient,poly2->power);
                //cout<<current->next->power<<" "<<current->next->coefficient<<endl;
                poly2=poly2->next;
                current=current->next;
            }
            else if(poly1->power == poly2->power)
            {
                int coeff = poly1->coefficient + poly2->coefficient;
                if(coeff!=0)
                {
                    current->next = new PolyNode(coeff,poly1->power);
                    current=current->next;
                }
                //cout<<current->next->power<<" "<<current->next->coefficient<<endl;
                poly1=poly1->next;
                poly2=poly2->next;
            }
            //current=current->next;
        }
        //current->next = NULL;
        return dummy->next;
    }
};
