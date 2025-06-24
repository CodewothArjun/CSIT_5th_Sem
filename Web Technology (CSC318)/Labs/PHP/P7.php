<html>
<head>
    <title>Button click</title>
</head>
<form method="post">
    <input type="submit" name="submitBtn" value="Click me">
</form>
</html>

<?php
if (isset($_POST["submitBtn"])) {
    echo "Button clicked!";
}
?>