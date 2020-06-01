const createNode = (value) => {
  return { value, left: null, right: null };
};

const insertNode = (tree, value) => {
  if (tree == null) {
    return createNode(value);
  }
  if (tree.value < value) {
    tree.right = insertNode(tree.right, value);
  } else {
    tree.left = insertNode(tree.left, value);
  }
  return tree;
};

const printInorder = (tree) => {
  if (tree == null) {
    return;
  }
  printInorder(tree.left);
  console.log(tree.value);
  printInorder(tree.right);
};

const printPreorder = (tree) => {
  if (tree == null) {
    return;
  }
  console.log(tree.value);
  printPreorder(tree.left);
  printPreorder(tree.right);
};

const printPostorder = (tree) => {
  if (tree == null) {
    return;
  }
  printPostorder(tree.left);
  printPostorder(tree.right);
  console.log(tree.value);
};

const main = () => {
  let tree = insertNode(null, 10);
  insertNode(tree, 20);
  insertNode(tree, 5);
  insertNode(tree, 1);
  insertNode(tree, 8);
  insertNode(tree, 15);
  insertNode(tree, 23);

  console.log('Inorder of tree');
  printInorder(tree);
  console.log('Preorder of tree');
  printPreorder(tree);
  console.log('Postorder of tree');
  printPostorder(tree);
};

main();
