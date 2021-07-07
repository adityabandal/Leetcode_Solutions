<h2>1542. Find Longest Awesome Substring</h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code>. An <em>awesome</em> substring is a non-empty substring of <code>s</code> such that we can make any number of swaps in order to make it palindrome.</p>

<p>Return the length of the maximum length <strong>awesome substring</strong> of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "3242415"
<strong>Output:</strong> 5
<strong>Explanation:</strong> "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "12345678"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "213123"
<strong>Output:</strong> 6
<strong>Explanation:</strong> "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "00"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> consists only of digits.</li>
</ul>
</div>