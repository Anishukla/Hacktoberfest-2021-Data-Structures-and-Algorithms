/* Creates Buttons and Lays Them Out */

var resultDiv = document.createElement('div');
resultDiv.id = 'res';
resultDiv.addEventListener('click', buttonClick);
document.body.appendChild(resultDiv);

var buttonsDiv = document.createElement('div');
buttonsDiv.id = 'btns';
document.body.appendChild(buttonsDiv);

var ids = ['btn0', 'btn1', 'btnClr', 'btnEql', 'btnSum', 'btnSub', 'btnMul', 'btnDiv'];
var innerHTMLs = ['0', '1', 'C', '=', '+', '-', '*', '/'];
var styles = ['binaryButton', 'binaryButton', 'utilityButton', 'utilityButton', 'operatorButton', 'operatorButton', 'operatorButton', 'operatorButton'];

for (var i = 0; i < ids.length; i++) {
    var button = document.createElement('button');
    button.innerHTML = innerHTMLs[i];
    button.id = ids[i];
    button.className = 'button ' + styles[i];
    button.addEventListener('click', buttonClick);
    buttonsDiv.appendChild(button);
}


/* Implements Calculator */

var operator = '';

function buttonClick(e) {
    var button = e.target || e.srcElement;

    /* If CLEAR, empty result box and last operator */
    if (button.id == 'btnClr') {
        operator = '';
        resultDiv.innerHTML = '';
    }
    /* If not CLEAR and not EQUALS, add to expression */
    else if (button.id != 'btnEql') {

        /* If operator was clicked */
        if (button.id != 'btn0' && button.id != 'btn1') {
            /* If operator was previously clicked, evaluate expression */
            if (operator != '') {
                evaluate();
            }
            /* Set current operator */
            operator = button.innerHTML;
        }

        /* Append pressed button to expression */
        resultDiv.innerHTML += button.innerHTML;
    }
    // else btnEeql, evaluate expression
    else {
        evaluate();
    }
}

function evaluate() {
    var operands = resultDiv.innerHTML.split(operator);
    /* */
    resultDiv.innerHTML = (
            Math.floor(
                eval(parseInt(operands[0], 2)
                + operator
                + parseInt(operands[1], 2))
            )
        ).toString(2);

    /* Clear previous operator */
    operator = '';
}
