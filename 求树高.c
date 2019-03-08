/*求树高*/

int height(BiTree t){
    int hLeft,hRight,hMax;
    if(t==NULL) return 0;
    hLeft=height(t->left);
    hRight=height(t->right);
    hMax=hLeft>hRight?hLeft:hRight;
    return 1+hMax;
}
