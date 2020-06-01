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

const search = (tree, value) => {
  if (tree == null) {
    console.log(value, ' not found in tree');
    return;
  }
  if (tree.value == value) {
    console.log(value, ' found in tree');
  } else if (tree.value < value) {
    search(tree.right, value);
  } else {
    search(tree.left, value);
  }
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

  search(tree, 15);
  search(tree, 10);
  search(tree, 5);
  search(tree, 55);
};

main();
