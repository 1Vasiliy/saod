public abstract class Tree {
    public TreeNode root;

    public abstract void insert(int[] values);

    public void traverseInOder(){
        if (root != null){
            root.traverseInOder();
        }
    }

    public TreeNode get(int value){
        if (root != null){
            return root.get(value);
        }
        return null;
    }

    public void delete(int value){
        root = delete(root, value);
    }

    private TreeNode delete(TreeNode subtreeRoot, int value){
        if (subtreeRoot == null){
            return subtreeRoot;
        }

        if (value < subtreeRoot.getData()){
            subtreeRoot.setLeftChild(delete(subtreeRoot.getLeftChild(), value));
        }
        else if (value > subtreeRoot.getData()){
            subtreeRoot.setRightChild(delete(subtreeRoot.getRightChild(), value));
        }
        else {
            if (subtreeRoot.getLeftChild() == null){
                return subtreeRoot.getRightChild();
            }
            else if (subtreeRoot.getRightChild() == null){
                return subtreeRoot.getLeftChild();
            }

            subtreeRoot.setData(subtreeRoot.getRightChild().min());
            subtreeRoot.setRightChild(delete(subtreeRoot.getRightChild(), subtreeRoot.getData()));
        }

        return subtreeRoot;
    }

    public int min(){
        if (root == null){
            return Integer.MIN_VALUE;
        }
        else return  root.min();
    }

    public int max(){
        if (root == null){
            return Integer.MAX_VALUE;
        }
        else return root.max();
    }

    public int treeSize(TreeNode node){
        if (node == null){
            return 0;
        }
        return 1 + treeSize(node.getLeftChild()) + treeSize(node.getRightChild());
    }

    public int treeSize(AVLnode node){
        if (node == null){
            return 0;
        }
        return 1 + treeSize(node.getLeftChild()) + treeSize(node.getRightChild());
    }

    public int treeHeight(TreeNode node){
        if (node == null){
            return 0;
        }
        return 1 + Math.max(treeHeight(node.getLeftChild()), treeHeight(node.getRightChild()));
    }
    public int treeHeight(AVLnode node){
        if (node == null){
            return 0;
        }
        return 1 + Math.max(treeHeight(node.getLeftChild()), treeHeight(node.getRightChild()));
    }

    public int treeSum(TreeNode node){
        if (node == null){
            return 0;
        }
        return node.getData() + treeSum(node.getLeftChild()) + treeSum(node.getRightChild());
    }

    public int treeSum(AVLnode node){
        if (node == null){
            return 0;
        }
        return node.getData() + treeSum(node.getLeftChild()) + treeSum(node.getRightChild());
    }

    private long lenSum(TreeNode node, long l)
    {
        if (node == null){
            return 0;
        }
        return l + lenSum(node.getLeftChild(), l + 1) + lenSum(node.getRightChild(), l + 1);
    }
    private long lenSum(AVLnode node, long l)
    {
        if (node == null){
            return 0;
        }
        return l + lenSum(node.getLeftChild(), l + 1) + lenSum(node.getRightChild(), l + 1);
    }

    public double averageHeight()
    {
        return lenSum(root, 1) * 1.0 / treeSize(root);
    }

    public double averageHeight(AVLnode root)
    {
        return lenSum(root, 1) * 1.0 / treeSize(root);
    }

    public void printInfo(){
        System.out.println("\n==========================================");
        System.out.println("Size of tree: " + treeSize(root));
        System.out.println("Control sum of tree: " + treeSum(root));
        System.out.println("Height of tree: " + treeHeight(root));
        System.out.println("Average height of tree: " + averageHeight());
        System.out.println("==========================================");
    }

}
