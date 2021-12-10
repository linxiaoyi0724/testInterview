////
////  test.cpp
////  testInterview
////
////  Created by linxiaoyi on 2021/12/2.
////
//
//
//
//
//// 习题1
//int atoi(const char* str)
//{
//    int num = 0;
//    int integerSign = 1;
//    
//    
//    if(str == nullptr)
//    {
//        return 0;
//    }
//    
//    while(*str == ' ')
//    {
//        str++;
//    }
//    
//    if(*str == '-')
//    {
//        integerSign = -1;
//    }
//    if(*str == '-' || *str == '+')
//    {
//        str++;
//    }
//    
//    while(*str >= '0' && *str <= '9')
//    {
//        num = num * 10 + *str - '0';
//        str++;
//    }
//    num = integerSign * num;
//    
//    return num;
//}
//
//
//
//
//
////习题2
//struct node {
//    int data;
//    node *next;
//    node():data(0),next(nullptr){}
//};
//
//
//node* reverse(node* head){
//    if (head == nullptr || head->next == nullptr)
//        return head;
// 
//    node *newHead = reverse(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//    
//    return newHead;
//}
//
//void Reverse(node* head){
//    head = reverse(head);
//}
//
//
//
////习题3
//struct Node
//{
//    Node *pNext;
//    Node *pRandom;
//    int data;
//    Node(int num):data(num),pNext(nullptr),pRandom(nullptr){}
//};
//
//void cloneNodes(Node* head)
//{
//    Node* temp;
//    Node* cur = head;
//    while (cur)
//    {
//        temp = new Node(cur->data);
//        temp->pNext = cur->pNext;
//        cur->pNext = temp;
//        cur = temp->pNext;
//    }
//}
//
//
//void copyNodeRandom(Node* head)
//{
//    Node* cur = head;
//    while (cur)
//    {
//        Node* next = cur->pNext;
//        if (cur->pRandom != nullptr){
//            next->pRandom = cur->pRandom->pNext;
//        }
//        cur = next->pNext;
//    }
//}
//
//
//Node* reconnectNode(Node* head)
//{
//    Node* cur = head;
//    Node* temp = nullptr;
//    Node* newHead = nullptr;
//    if (cur)
//    {
//        temp = cur->pNext;
//        newHead = cur->pNext;
//        cur->pNext = temp->pNext;
//        cur = temp->pNext;
//    }
//    while (cur)
//    {
//        temp->pNext = cur->pNext;
//        temp = temp->pNext;
//        cur->pNext = temp->pNext;
//        cur = temp->pNext;
//    }
//    return newHead;
//}
//
//
//
//Node *copyList(Node* head){
//    if (head)
//    {
//        cloneNodes(head);
//        copyNodeRandom(head);
//        reconnectNode(head);
//    }
//    return nullptr;
//}
//
//
//
//
//
////习题4
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
//
//int find(int arr[], int N, int K){
//    quickSort(arr, 0, N-1);
//    return arr[N-K];
//}
