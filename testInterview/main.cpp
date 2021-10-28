//
//  main.cpp
//  testInterview
//
//  Created by linxiaoyi on 2021/10/21.
//


//
//void quickSort(int arr[], int left, int right){
//    if(left > right){
//        return;
//    }
//    int i, j, base, temp;
//    i = left;
//    j = right;
//    base = arr[left];
//    while (i < j) {
//        while (arr[j] >= base && i < j) {
//            j--;
//        }
//        while (arr[i] <= base && i < j) {
//            i++;
//        }
//        if(i < j){
//            temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//        }
//    }
//    arr[left] = arr[i];
//    arr[i] = base;
//    quickSort(arr, left, i-1);
//    quickSort(arr, i+1, right);
//}
//
//void bubbleSort(int arr[], int N){
//    for (int i = 0; i < N-1; i++) {
//        for (int j = 0; j < N-1; j++) {
//            if(arr[j] > arr[j+1]){
//                int temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//        }
//    }
//}



    






















//// 链表
//#include <iostream>
//#include <vector>
//
//struct listNode {
//    int data;
//    listNode *next;
//    listNode():data(0),next(nullptr){}
//};
//
//
//void creatList(listNode* list, std::vector<int> a){
//    listNode* p = list;
//    for(int i = 0; i < a.size();i++){
//        listNode* node = new listNode;
//        node->data = a[i];
//        node->next = nullptr;
//
//        p->next = node;
//        p = p->next;
//    }
//}
//
//void insertList(listNode* list, int index, int num){
//    listNode* p = list;
//    for(int i = 1; i < index-1; i++){
//        p= p->next;
//    }
//    listNode* node = new listNode;
//    node->data = num;
//    node->next = p->next;
//    p->next = node;
//}
//
//void deleteList(listNode* list, int index){
//    listNode* p = list;
//    for(int i = 1; i < index-1; i++){
//        p = p->next;
//    }
//    listNode* q = p->next;
//    p->next = p->next->next;
//    delete q;
//
//}
//
//listNode* reverseList(listNode* list){
//    listNode* p = list;
//    listNode* pre = nullptr;
//    listNode* temp = nullptr;
//    while (p) {
//        temp = p->next;
//        p->next = pre;
//        pre = p;
//        p = temp;
//    }
//    return pre;
//}
//
//void printList(listNode* list){
//    listNode* p = list;
//    while (p) {
//        std::cout<< p->data<< "   ";
//        p=p->next;
//
//    }
//}
//
//void getMiddleAndTailList(listNode* list, listNode* &middle, listNode* &tail){
//    listNode* slow = list;
//    listNode* fast = list;
//    while (1) {
//        slow = slow->next;
//        for(int i = 0; i != 2; i++){
//            if(fast->next == nullptr){
//                middle = slow;
//                tail = fast;
//                return;
//            }
//            fast = fast->next;
//        }
//    }
//}
//
//listNode* reverseList1(listNode* list){
//    listNode * p = list;
//    listNode * mhead = list;
//    listNode * q = list->next;
//    while(p->next!=list){
//        listNode * r = q->next;
//        p->next = r;
//        q->next = mhead;
//        mhead   = q;
//        q = p->next;
//    }
//    p->next = NULL;
//    return mhead;
//}
//
//listNode* swapPair(listNode* list){
//    listNode* middleList = nullptr;
//    listNode* tailList = nullptr;
//
//    getMiddleAndTailList(list, middleList, tailList);
//    tailList->next = list;
//
//    return reverseList1(middleList);
//
//}
//
//
//
//int main(){
//    std::vector<int> arr = {1,2,3,4,5,6};
//    listNode* list = new listNode;
//    creatList(list,arr);
//    printList(list->next);
//    std::cout << std::endl;
//
////    链表的插入
////    insertList(list->next, 2, 100);
////    printList(list->next);
//
////    链表的删除
////    deleteList(list->next, 2);
////    printList(list->next);
//
////    链表的反转
////    printList(reverseList(list->next));
//
//
////    链表中间反转
//    printList(swapPair(list->next));
//
//}


























// 二叉树
#include <iostream>
#include <vector>

int nodeTree;

struct BINode {
    int data;
    BINode *lChild, *rChild;
    BINode():data(0),lChild(nullptr),rChild(nullptr){}
};

BINode* createBITree(std::vector<int> a){
    BINode *T = new BINode;
    nodeTree++;
    if(nodeTree > a.size()-1){
        return nullptr;
    }
    T->data = a[nodeTree];
    T->lChild = createBITree(a);
    T->rChild = createBITree(a);
    return  T;
}

void preOrderTraverse(BINode *T){
    if(T){
        std::cout << T->data << "  ";
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
}

void inOrderTraverse(BINode *T){
    if(T){
        inOrderTraverse(T->lChild);
        std::cout << T->data << "  ";
        inOrderTraverse(T->rChild);
    }
}

void postOrderTraverse(BINode *T){
    if(T){
        postOrderTraverse(T->lChild);
        std::cout << T->data << "  ";
        postOrderTraverse(T->rChild);
    }
}

void destoryBTTree(BINode* &BT){
    if(BT != nullptr){
        destoryBTTree(BT->lChild);
        destoryBTTree(BT->rChild);
        free(BT);
        BT=nullptr;
    }
}

//查找节点
BINode* findBTNode(BINode* &BT, int data){
    if(BT == nullptr){
        return nullptr;
    }
    else if(BT->data == data){
        std::cout << "存在该节点: " << data << std::endl;
        return BT;
    }
    else{
        BINode* p;
        p = findBTNode(BT->lChild, data);
        if(p!=nullptr){
            return p;
        }else
        {
            return findBTNode(BT->rChild, data);
        }
    }
}

//求二叉树的高度
int BTHeight(BINode* &BT){
    int lChild;
    int rChild;
    int h;
    if(BT == nullptr){
        return 0;
    }
    else
    {
        lChild = BTHeight(BT->lChild);
        rChild = BTHeight(BT->rChild);
        h = (lChild > rChild)?(lChild + 1):(rChild +1);
        return h;
    }
}

//输出二叉树
void displayBTNode(BINode *&BT){
    if(BT != nullptr){
        std::cout << BT->data << " ";
        if(BT->lChild != nullptr || BT->rChild != nullptr){
            displayBTNode(BT->lChild);
            displayBTNode(BT->rChild);
        }
    }
}


int main(){
    nodeTree = -1;
    std::vector<int> arr ={1,2,3,4,5,6,7,8};
    BINode *T = createBITree(arr);
    preOrderTraverse(T);
    std::cout << std::endl;
    inOrderTraverse(T);
    std::cout << std::endl;
    postOrderTraverse(T);
    std::cout << std::endl;
    
    findBTNode(T, 5);
    
    int BTtreeHeight = BTHeight(T);
    std::cout << "the BT tree height is: " << BTtreeHeight << std::endl;
    displayBTNode(T);
//    destoryBTTree(T);
    
}
