<!DOCTYPE html>
<html>
<head>
    <title>Push Swap Project - 42 School</title>
</head>
<body>
    <h1>Push Swap Project - 42 School</h1>

    <h2>Project Overview</h2>
    <p>This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to sort the stack with the minimum possible number of operations. The algorithm used in this project is highly efficient and involves dynamic programming, which makes the source code quite large compared to other stack sorting algorithms.</p>

    <h2>Instructions</h2>
    <p>The project uses two stacks, <code>a</code> and <code>b</code>, and the following operations:</p>
    <ul>
        <li><code>sa</code> : swap the first 2 elements at the top of stack <code>a</code>. Do nothing if there is only one or no elements.</li>
        <li><code>sb</code> : swap the first 2 elements at the top of stack <code>b</code>. Do nothing if there is only one or no elements.</li>
        <li><code>ss</code> : <code>sa</code> and <code>sb</code> at the same time.</li>
        <li><code>pa</code> : take the first element at the top of <code>b</code> and put it at the top of <code>a</code>. Do nothing if <code>b</code> is empty.</li>
        <li><code>pb</code> : take the first element at the top of <code>a</code> and put it at the top of <code>b</code>. Do nothing if <code>a</code> is empty.</li>
        <li><code>ra</code> : shift up all elements of stack <code>a</code> by 1. The first element becomes the last one.</li>
        <li><code>rb</code> : shift up all elements of stack <code>b</code> by 1. The first element becomes the last one.</li>
        <li><code>rr</code> : <code>ra</code> and <code>rb</code> at the same time.</li>
        <li><code>rra</code> : shift down all elements of stack <code>a</code> by 1. The last element becomes the first one.</li>
        <li><code>rrb</code> : shift down all elements of stack <code>b</code> by 1. The last element becomes the first one.</li>
        <li><code>rrr</code> : <code>rra</code> and <code>rrb</code> at the same time.</li>
    </ul>

    <h2>Building and Running</h2>
    <p>To compile the project, run:</p>
    <pre><code>make</code></pre>
    <p>To run the project, use:</p>
    <pre><code>./push_swap [numbers to sort]</code></pre>

    <h2>Algorithm and Efficiency</h2>
    <p>The algorithm used in this project is a highly efficient sorting algorithm specifically designed for this type of stack sorting problem. It uses dynamic programming to optimize the sorting process, which results in a larger source code compared to other stack sorting algorithms. However, the increased code complexity leads to a more efficient sorting process, making it a worthwhile trade-off.</p>

    <h2>Author</h2>
    <p>Mohamed Amine IGUIJI</p>

    <h2>License</h2>
    <p>This project is licensed under the <a href="LICENSE">MIT License</a>.</p>
</body>
</html>
