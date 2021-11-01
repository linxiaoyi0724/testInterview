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

























//
//// 二叉树
//#include <iostream>
//#include <vector>
//
//int nodeTree;
//
//struct BINode {
//    int data;
//    BINode *lChild, *rChild;
//    BINode():data(0),lChild(nullptr),rChild(nullptr){}
//};
//
//BINode* createBITree(std::vector<int> a){
//    BINode *T = new BINode;
//    nodeTree++;
//    if(nodeTree > a.size()-1){
//        return nullptr;
//    }
//    T->data = a[nodeTree];
//    T->lChild = createBITree(a);
//    T->rChild = createBITree(a);
//    return  T;
//}
//
//void preOrderTraverse(BINode *T){
//    if(T){
//        std::cout << T->data << "  ";
//        preOrderTraverse(T->lChild);
//        preOrderTraverse(T->rChild);
//    }
//}
//
//void inOrderTraverse(BINode *T){
//    if(T){
//        inOrderTraverse(T->lChild);
//        std::cout << T->data << "  ";
//        inOrderTraverse(T->rChild);
//    }
//}
//
//void postOrderTraverse(BINode *T){
//    if(T){
//        postOrderTraverse(T->lChild);
//        std::cout << T->data << "  ";
//        postOrderTraverse(T->rChild);
//    }
//}
//
//void destoryBTTree(BINode* &BT){
//    if(BT != nullptr){
//        destoryBTTree(BT->lChild);
//        destoryBTTree(BT->rChild);
//        free(BT);
//        BT=nullptr;
//    }
//}
//
////查找节点
//BINode* findBTNode(BINode* &BT, int data){
//    if(BT == nullptr){
//        return nullptr;
//    }
//    else if(BT->data == data){
//        std::cout << "存在该节点: " << data << std::endl;
//        return BT;
//    }
//    else{
//        BINode* p;
//        p = findBTNode(BT->lChild, data);
//        if(p!=nullptr){
//            return p;
//        }else
//        {
//            return findBTNode(BT->rChild, data);
//        }
//    }
//}
//
////求二叉树的高度
//int BTHeight(BINode* &BT){
//    int lChild;
//    int rChild;
//    int h;
//    if(BT == nullptr){
//        return 0;
//    }
//    else
//    {
//        lChild = BTHeight(BT->lChild);
//        rChild = BTHeight(BT->rChild);
//        h = (lChild > rChild)?(lChild + 1):(rChild +1);
//        return h;
//    }
//}
//
////输出二叉树
//void displayBTNode(BINode *&BT){
//    if(BT != nullptr){
//        std::cout << BT->data << " ";
//        if(BT->lChild != nullptr || BT->rChild != nullptr){
//            displayBTNode(BT->lChild);
//            displayBTNode(BT->rChild);
//        }
//    }
//}
//
//
//int main(){
//    nodeTree = -1;
//    std::vector<int> arr ={1,2,3,4,5,6,7,8};
//    BINode *T = createBITree(arr);
//    preOrderTraverse(T);
//    std::cout << std::endl;
//    inOrderTraverse(T);
//    std::cout << std::endl;
//    postOrderTraverse(T);
//    std::cout << std::endl;
//
//    findBTNode(T, 5);
//
//    int BTtreeHeight = BTHeight(T);
//    std::cout << "the BT tree height is: " << BTtreeHeight << std::endl;
//    displayBTNode(T);
////    destoryBTTree(T);
//
//}







#include <iostream>
#include <stack>
using namespace std;
 
// 树的三种遍历的循环实现
// 用到了栈，也可以用前面自己写的数据结构
typedef struct _TreeNode
{
    int _data;
    struct _TreeNode* _left;
    struct _TreeNode* _right;
}TreeNode;
 
 
// 先序遍历
void preOrderIterator(TreeNode *root){
    if (root)
    {
        stack<TreeNode*> s;
        while(root || !s.empty()){    // 只要root不为空
            // 一路压栈
            while(root){    // r非空
                cout << root->_data << " ";
                s.push(root);
                root = root->_left;    // 将r取为r的左节点
            }
            // 出栈 - 类似于dfs，在s栈空前一直寻找有右节点的，把右节点压栈输出然后继续寻找这个右节点的左节点
            root = s.top();
            s.pop();
            root = root->_right;
        }
    }
}
 
// 中序遍历
void midOrderIterator(TreeNode *root){
    if (root)
    {
        stack<TreeNode*> s;
        while(root || !s.empty()){    // 只要root不为空
            // 一路压栈
            while(root){    // r非空
                s.push(root);
                root = root->_left;    // 将r取为r的左节点
            }
            // 出栈 - 类似于dfs，在s栈空前一直寻找有右节点的，把右节点压栈输出然后继续寻找这个右节点的左节点
            root = s.top();
            s.pop();
            cout << root->_data << " ";
            root = root->_right;
        }
    }
}
 
// 后序遍历
void postOrderIterator(TreeNode *root){
    if (root)
    {
        stack<TreeNode*> s;
        TreeNode* cur;    // 当前节点
        TreeNode* pre = NULL; // 上一次访问的节点
        s.push(root);
        while(!s.empty()){
            cur = s.top();s.pop();    // 先取出栈顶的节点,得到节点的值
            s.push(cur);    // 再把节点放回去
 
            // 如果当前节点没有子节点 或者 子节点都已经被访问过了
            if ((cur->_left==NULL && cur->_right==NULL) || (pre!=NULL && (pre==cur->_left || pre==cur->_right)))
            {
                cout << cur->_data << " ";
                s.pop();
                pre = cur;
            }else{
                if (cur->_right != NULL) s.push(cur->_right);
                if (cur->_left != NULL) s.push(cur->_left);
            }
 
        }
        
    }
}
 
 
int main(int argc, char const *argv[])
{
    TreeNode a, b, c, d, e, f;
    // 创建一个指向根节点的指针
    TreeNode* root  = &a;
    a._data = 1;
    b._data = 2;
    c._data = 3;
    d._data    = 4;
    e._data = 5;
    f._data = 6;
    a._left = &b;
    a._right = &c;
    b._left = &d;
    b._right = &e;
    c._left = NULL;
    c._right = &f;
    d._left = d._right = NULL;
    e._left = e._right = NULL;
    f._left = f._right = NULL;
 
    preOrderIterator(root);
    cout << endl;
    midOrderIterator(root);
    cout << endl;
    postOrderIterator(root);
    cout << endl;
 
    return 0;
}
