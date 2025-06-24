<!DOCTYPE html>
<html>
<head>
  <title>PHP Form Validation</title>
  <style>
    body { font-family: Arial; background-color: #f9f9f9; padding: 30px; }
    form { background: #fff; padding: 20px; border-radius: 10px; width: 400px; margin: auto; box-shadow: 0 0 10px #ccc; }
    input, select { width: 100%; padding: 10px; margin: 10px 0; }
    .error { color: red; font-size: 14px; }
  </style>
</head>
<body>

<?php
// Define variables and initialize
$name = $email = $phone = "";
$nameErr = $emailErr = $phoneErr = "";
$success = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    // Validate name
    if (empty($_POST["name"])) {
        $nameErr = "Name is required";
    } else {
        $name = trim($_POST["name"]);
        if (!preg_match("/^[a-zA-Z\s]{6,}$/", $name)) {
            $nameErr = "Name must be at least 6 characters and contain only letters and spaces";
        }
    }

    // Validate email
    if (empty($_POST["email"])) {
        $emailErr = "Email is required";
    } else {
        $email = trim($_POST["email"]);
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
        }
    }

    // Validate phone
    if (empty($_POST["phone"])) {
        $phoneErr = "Phone number is required";
    } else {
        $phone = trim($_POST["phone"]);
        if (!preg_match("/^(98|97)\d{8}$/", $phone)) {
            $phoneErr = "Phone must start with 98 or 97 and be 10 digits long";
        }
    }

    // Final success message
    if ($nameErr == "" && $emailErr == "" && $phoneErr == "") {
        $success = "Form submitted successfully!";
    }
}
?>

<h2 align="center">PHP Validated Form</h2>

<form method="post" action="">
  <label>Name:</label>
  <input type="text" name="name" value="<?= htmlspecialchars($name); ?>">
  <span class="error"><?= $nameErr; ?></span>

  <label>Email:</label>
  <input type="text" name="email" value="<?= htmlspecialchars($email); ?>">
  <span class="error"><?= $emailErr; ?></span>

  <label>Phone:</label>
  <input type="text" name="phone" value="<?= htmlspecialchars($phone); ?>">
  <span class="error"><?= $phoneErr; ?></span>

  <input type="submit" value="Submit">
</form>

<?php if ($success): ?>
  <p style="color:green; text-align:center;"><strong><?= $success; ?></strong></p>
<?php endif; ?>

</body>
</html>
