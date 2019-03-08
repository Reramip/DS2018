int JudgeTwoListCrossed(List L1,List L2){
    while(L1->next!=NULL)L1=L1->next;
    while(L2->next!=NULL)L2=L2->next;
    if(L1==L2) return 1;
    else return 0;
}