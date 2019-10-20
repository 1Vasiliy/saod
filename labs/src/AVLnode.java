public class AVLnode {
    public int h = 1;
    public int balance = 0;
    public int data;
    public AVLnode leftChild, rightChild, father;

    public AVLnode getLeftChild() {
        return leftChild;
    }

    public int getData() {
        return data;
    }

    public AVLnode getRightChild() {
        return rightChild;
    }

    public AVLnode(int data, AVLnode father) {
        this.data = data;
        this.father = father;
    }

    public void traverseInOder(){
        if (leftChild != null){
            leftChild.traverseInOder();
        }

        System.out.print(data + ", ");

        if (rightChild != null){
            rightChild.traverseInOder();
        }
    }

    public AVLnode min(){
        if (leftChild == null){
            return this;
        }
        else
            return leftChild.min();
    }

}
