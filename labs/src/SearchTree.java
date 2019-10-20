public class SearchTree extends Tree {

    @Override
    public void insert(int[] values) {
        for (int value:values) {
            if (root == null) {
                root = new TreeNode(value);
            } else {
                root.insert(value);
            }
        }
    }

    public void insert(int value){
        if (root == null){
            root = new TreeNode(value);
            return;
        }

        TreeNode node = root;

        while (true){
            if (value < node.getData() && node.getLeftChild() != null){
                node = node.getLeftChild();
            } else if (value > node.getData() && node.getRightChild() != null){
                node = node.getRightChild();
            } else if (value == node.getData()){
                return;
            } else
                break;
        }

        if (value < node.getData()){
            node.setLeftChild(new TreeNode(value));
        } else
            node.setRightChild(new TreeNode(value));
    }
}
