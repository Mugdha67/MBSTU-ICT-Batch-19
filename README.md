<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Input Form</title>
    
</head>
<body>
    <div class="form-container">
        <h1>Input Form</h1>
        <form action="#" method="post">
            <div class="form-row">
                <label>First Name:</label>
                <input type="text" name="firstName" required><br>
                <label>Last Name:</label>
                <input type="text" name="lastName" required><br>
            </div>

            <div class="form-row">
                <label>User Name:</label>
                <input type="text" name="userName" required><br>
                <label>Password:</label>
                <input type="password" name="password" required><br>
            </div>

            <div class="form-row">
                <label>Gender:</label>
                <div class="radio-group">
                    <input type="radio" name="gender" value="male" id="male">
                    <label for="male">Male</label>
                    <input type="radio" name="gender" value="female" id="female">
                    <label for="female">Female</label>
                </div>
            </div>

            <div class="form-row">
                <label>Religion:</label>
                <div class="checkbox-group">
                    <input type="checkbox" name="religion" value="muslim" id="muslim">
                    <label for="muslim">Muslim</label>
                    <input type="checkbox" name="religion" value="others" id="others">
                    <label for="others">Others</label>
                </div>
            </div>

            <div class="form-row">
                <label>IT Expert:</label>
                <div class="checkbox-group">
                    <input type="checkbox" name="expertise" value="hardware" id="hardware">
                    <label for="hardware">Hardware Expert</label>
                    <input type="checkbox" name="expertise" value="software" id="software">
                    <label for="software">Software Expert</label>
                    <input type="checkbox" name="expertise" value="graphic" id="graphic">
                    <label for="graphic">Graphic Designer</label>
                    <input type="checkbox" name="expertise" value="network" id="network">
                    <label for="network">Network Expert</label>
                </div>
            </div>

            <div class="form-row">
                <label>Select Department:</label>
                <select name="department">
                    <option value="CIS">CIS</option>
                    <option value="CSE">CSE</option>
                    <option value="EEE">EEE</option>
                    <option value="BBA">BBA</option>
                </select>
            </div>

            <div class="form-row" style="text-align: center; margin-top: 20px;">
                <input type="submit" value="Submit">
            </div>
        </form>
    </div>
</body>
</html>
