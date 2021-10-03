import rotateList from "./index";

/**
 * Definition for singly-linked list
 * @param {number} val
 * @param {ListNode} next
 */
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Convert node to array
 * @param {ListNode} listNode
 * @returns {number[]}
 */
function nodeToArray(listNode) {
  let list = [];

  while (listNode) {
    list = [...list, listNode.val];
    listNode = listNode.next;
  }

  return list;
}

test("rotate-list", () => {
  const head = new ListNode(
    1,
    new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))
  );
  expect(nodeToArray(head)).toEqual([1, 2, 3, 4, 5]);

  const rotateHead = rotateList(head, 2);
  expect(nodeToArray(rotateHead)).toEqual([4, 5, 1, 2, 3]);
});
