public class AVLtree extends Tree{
    private AVLnode root = null;


    @Override
    public void insert(int[] values) {
        root = new AVLnode(values[0], null);
        for ( int i = 1; i < values.length; i++){
            root = insert(root, values[i], null);
        }
    }

    @Override
    public void traverseInOder(){
        if (root != null){
            root.traverseInOder();
        }
    }

    public AVLnode insert(AVLnode node, int value, AVLnode father) {
        if (node.data == value){
            return node;
        }

        if (value < node.data){
            if (node.leftChild == null){
                node.leftChild = new AVLnode(value, node);
            }
            else {
                node.leftChild = insert(node.leftChild, value, node);
            }
            node.h = treeHeight(node);
        }
        else {
            if (node.rightChild == null){
                node.rightChild = new AVLnode(value, father);
            }
            else{
                node.rightChild = insert(node.rightChild, value, node);
            }
            node.h = treeHeight(node);
        }

        node.balance = balance(node);

        if(node.balance == -2) {
            node = leftRotation(node);
        } else if(node.balance == 2){
            node = rightRotation(node);
        }

        return node;
    }



    public static int balance(AVLnode root){
        if(root.leftChild == null && root.rightChild == null) return 0;
        else if(root.leftChild == null) return -(root.rightChild.h);
        else if(root.rightChild == null) return root.leftChild.h;
        return root.leftChild.h - root.rightChild.h;
    }

    private AVLnode leftRotation(AVLnode root) {
        if (root.rightChild.rightChild == null && root.rightChild.leftChild != null) {
            root.rightChild = rightRotation(root.rightChild);
            root = leftRotation(root);
        } else if(root.rightChild.leftChild == null || root.rightChild.leftChild.h <= root.rightChild.rightChild.h){
            AVLnode newNode = root.rightChild;
            newNode.father = root.father;
            root.rightChild = newNode.leftChild;
            if(root.rightChild != null)
                root.rightChild.father = root;
            root.h = treeHeight(root);
            root.father = newNode;
            root.balance = balance(root);
            newNode.leftChild = root;
            root = newNode;
            root.balance = balance(root);
            root.h = treeHeight(root);
        } else {
            root.rightChild = rightRotation(root.rightChild);
            root = leftRotation(root);
        }
        return root;
    }

    private AVLnode rightRotation(AVLnode root){
        if (root.leftChild.rightChild != null && root.leftChild.leftChild == null) {
            root.leftChild = leftRotation(root.leftChild);
            root = rightRotation(root);
        } else if(root.leftChild.rightChild == null || root.leftChild.rightChild.h <= root.leftChild.leftChild.h) {
            AVLnode newNode = root.leftChild;
            newNode.father = root.father;
            root.leftChild = newNode.rightChild;
            if(root.leftChild != null)
                root.leftChild.father = root;
            root.h = treeHeight(root);
            root.father = newNode;
            root.balance = balance(root);
            newNode.rightChild = root;
            root = newNode;
            root.balance = balance(root);
            root.h = treeHeight(root);
        } else {
            root.leftChild = leftRotation(root.leftChild);
            root = rightRotation(root);
        }
        return root;
    }

    @Override
    public void printInfo(){
        System.out.println("\n==========================================");
        System.out.println("Size of tree: " + treeSize(root));
        System.out.println("Control sum of tree: " + treeSum(root));
        System.out.println("Height of tree: " + treeHeight(root));
        System.out.println("Average height of tree: " + averageHeight(root));
        System.out.println("==========================================");
    }
}
