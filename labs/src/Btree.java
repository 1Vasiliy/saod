public class Btree {
    public Bnode root;
    private final int t = 2;

    public void create(Btree tree) {
        Bnode x = new Bnode();
        x.leaf = true;
        x.n = 0;
        tree.root = x;
    }

    /* function implements splitting root */
    public void insert(Btree tree, Integer k) {
        Bnode r = tree.root; //saving the root
        int i = r.n;
        if (r.leaf){
            while (i >= 1 && k < r.key[i]) {  // insert k value to the right place in the node
                r.key[i + 1] = r.key[i];
                i--;
            }
            r.key[i + 1] = k;
            r.n++; // increase num of values in the current node
        } else {
            while (i >= 1 && k < r.key[i]) { // find key value (index) in the node which is less then our key value
                i--;
            }
            i++; // index of child we move
            insertToNode(r, i, k);
        }

        if (r.n == t + 1) { // if the root is full
            Bnode s = new Bnode(); // create empty node
            tree.root = s; // make it root
            s.leaf = false; // new node not a leaf
            s.n = 0; // it has zero values
            s.c[1] = r; // first child is a link to the old root
            splitChild(s, 1); // split old(full) root which is the first s's child
        }
    }

    private void insertToNode(Bnode x, int i, Integer k) {
        int j = x.c[i].n; // save num of key values in the x node
        if (x.c[i].leaf) { // if x node is a leaf
            while (j >= 1 && k < x.c[i].key[j]) {  // insert k value to the right place in the node
                x.c[i].key[j + 1] = x.c[i].key[j];
                j--;
            }
            x.c[i].key[j + 1] = k;
            x.c[i].n++; // increase num of values in the current node

            if (x.c[i].n == t + 1){
                splitChild(x, i);
            }
            // FIXME recursively check full node to be add. FIXED
        } else { //if node is not a leaf
            while (j >= 1 && k < x.c[i].key[j]) { // find key value (index) in the node which is less then our key value
                j--;
            }
            j++; // index of child we move

            insertToNode(x.c[i], j, k);
            if (x.c[i].n == t + 1){
                splitChild(x, i);
            }
        }
    }

    /**
     *
     * @param x is node which child to be splitted
     * @param i index of splitting child
     */
    private void splitChild(Bnode x, int i) {
        Bnode z = new Bnode(); // create new empty node which will be the second part of splitting node
        Bnode y = x.c[i]; // create new node which is equal child to be split

        z.leaf = y.leaf; // both on the same level
        z.n = t / 2;

        for (int j = 1; j <= t / 2 ; j++) { // writing half of numbers from first to second node
            z.key[j] = y.key[j + t / 2 + 1]; // average value not include
        }

        if (!y.leaf) { // if splitting node is not a leaf
            for (int j = 1; j <= t / 2 + 1; j++) {  // write second and third children from first to second node
                z.c[j] = y.c[j + t / 2 + 1];
            }
        }
        y.n = t / 2; // one element left
        // maybe excess element in y need to be removed ???? yes.

//        for (int j = x.n + 1; j >= i + 1; j--) { // FROM num of elements in the node + 1
//            x.c[j + 1] = x.c[j];                 // DOWNTO index of splitting child + 1
//        }

        int j = x.n;
        Integer k = y.key[t];
        // set children so: y at the same place, z at the y place + 1
        while (j >= 1 && k < x.key[j]) {
            x.key[j + 1] = x.key[j];
            x.c[j + 2] = x.c[j + 1]; // right will always allowed for writing
            j--;
        }
        x.key[j + 1] = k;
        x.n++; // increase num of values in the current node

        y.key[t] = null;
        y.key[t + 1] = null;

        x.c[j + 2] = z; // make second node as a child of x
        x.c[j + 1] = y; // necessary? yes.
    }

    public void traversal(Bnode node){
        int i;
        if (node != null){
            for (i = 1; i <= node.n; i++){
                traversal(node.c[i]);
                System.out.print(node.key[i] + " ");
            }
            traversal(node.c[i]);
        }
    }
}