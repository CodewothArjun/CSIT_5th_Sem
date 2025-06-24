function validation() {
    // Name Validation
    const name = document.getElementById("name").value.trim();
    if (name === "") {
        alert("Name cannot be empty!");
        return false;
    }
    if (!/^[A-Za-z ]+$/.test(name)) {
        alert("Name should contain only letters and spaces!");
        return false;
    }
    
    // Email Validation
    const email = document.getElementById("email").value.trim();
    if (email === "") {
        alert("Email cannot be empty!");
        return false;
    }
    if (!/\S+@\S+\.\S+/.test(email)){
        alert("Invalid email format!");
        return false;
    }

    // Password Validation
    const password = document.getElementById("password").value;
    if (password === "") {
        alert("Password cannot be empty!");
        return false;
    }
    if (password.length < 6) {
        alert("Password must be at least 6 characters long!");
        return false;
    }

    // Phone Number Validation
    const number = document.getElementById("number").value.trim();
    if (number === "") {
        alert("Phone number cannot be empty!");
        return false;
    }
    if (!/^\d{10}$/.test(number)) {
        alert("Phone number must be 10 digits!");
        return false;
    }

    // Gender Validation
    const genderSelected = document.querySelector('input[name="gender"]:checked');
    if (!genderSelected) {
        alert("Please select a gender!");
        return false;
    }

    // If all validations pass
    alert("Form submitted successfully!");
    return true;
}

// Attach validation to the submit button
document.querySelector('input[type="button"]').addEventListener('click', validation);

