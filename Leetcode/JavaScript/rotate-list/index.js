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
 * Rotate list
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
function rotateList(head, k) {
  if (!head) return head;

  /**
   * Swap list (val / next)
   * @param {ListNode} listNode
   * @returns {ListNode}
   */
  function rotate(listNode) {
    const current = listNode;

    /**
     * Compute list length
     * @param {*} listNode
     * @returns {number}
     */
    function getLength(listNode) {
      let length = 0;

      while (listNode) {
        listNode = listNode.next;
        length++;
      }

      return length;
    }

    const length = getLength(current);

    if (length === 1) return listNode;

    /**
     * Get node (by length)
     * @param {ListNode} listNode
     * @param {number} length
     * @returns {ListNode}
     */
    function findNode(listNode, length) {
      let i = 0;

      while (i < length - 1) {
        listNode = listNode.next;
        i++;
      }

      return listNode;
    }

    const node = findNode(listNode, length);
    let temp = head;

    temp = findNode(temp, length - 1);
    temp.next = null;
    node.next = head;

    return node;
  }

  for (let i = 0; i < k; i++) {
    head = rotate(head);
  }

  return head;
}

export default rotateList;
