public class TreeNode {
    private TreeNode leftChild;
    private TreeNode rightChild;

    private int data;

    public TreeNode(int data){
        this.data = data;
    }

    public void insert(int value){
        if (data == value){
            return;
        }

        if (value < data){
            if (leftChild == null){
                leftChild = new TreeNode(value);
            }
            else {
                leftChild.insert(value);
            }
        }
        else {
            if (rightChild == null){
                rightChild = new TreeNode(value);
            }
            else{
            rightChild.insert(value);
            }
        }

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

    public TreeNode get(int value){
        if (value == data){
            return this;
        }

        if (value < data){
            if (leftChild != null){
                return leftChild.get(value);
            }
        } else {
            if (rightChild != null){
                return rightChild.get(value);
            }
        }

        return null;
    }

    public int min(){
        if (leftChild == null){
            return data;
        }
        else
            return leftChild.min();
    }

    public int max(){
        if (rightChild == null){
            return data;
        }
        else
            return rightChild.max();
    }

    public TreeNode getLeftChild() {
        return leftChild;
    }

    public void setLeftChild(TreeNode leftChild) {
        this.leftChild = leftChild;
    }

    public TreeNode getRightChild() {
        return rightChild;
    }

    public void setRightChild(TreeNode rightChild) {
        this.rightChild = rightChild;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "Data = " + data;
    }
}
