public class PerfSearchTree extends Tree {

    @Override
    public void insert(int[] values){
        super.root = insertPerfect(values, 0, values.length - 1);
    }


    private TreeNode insertPerfect(int[] values, int left, int right){
        if (left > right){
            return null;
        }

        int index = (left + right) / 2;

        TreeNode root = new TreeNode(values[index]);

        root.setLeftChild(insertPerfect(values, left, index - 1));
        root.setRightChild(insertPerfect(values, index + 1, right));

        return root;
    }
}
