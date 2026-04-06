# Contribution Guidelines

Welcome to the team! To keep our project professional and organized, please follow this workflow:

## Step 1: Set Up the Project on Your Computer (Do this once)
Before you can work, you need a copy of the project.
1. Open our Project Repository on GitHub.
2. Click the green **"Code"** button (top right).
3. Copy the **HTTPS link** (starts with `https://github.com...`).
4. Open your computer's **Terminal** (Mac) or **Command Prompt/Git Bash** (Windows).
5. Navigate to the folder where you want to save the project (e.g., `cd Desktop`).
6. Type the following command and paste the link:

   ```bash
   git clone https://github.com/[YOUR_USERNAME]/OpenGL-Flag-Logo-Renderer.git

   cd OpenGL-Flag-Logo-Renderer

---

## Step 2: Create a Branch (Your private workspace)
CRITICAL RULE: Never write code or edit files directly on the main branch.

1. Update Local Code: Always get the latest version from the leader first:

         git pull origin main

2. Create a Branch: Create a branch for your specific Task/Issue:

         git checkout -b task-name-yourname

---

## Step 3: Working & Saving Changes
Now you can open VS Code and complete your assigned task (e.g., editing docs/report.md).

1. Save Files: Save all your changes in VS Code.

2. Stage Changes: Tell Git which files you want to prepare for saving:

         git add .

3. Commit Work: Save the changes to your local history with a professional message:

         git commit -m "docs: added the first section of the technical report"

---

## Step 4: Submitting Your Work (Push & Pull Request)
Once you finish your task, you need to send it to the leader for review.

1. Push to GitHub: Send your branch to the online repository:
git push origin task-name-yourname
2. Open Pull Request (PR):

  - Go to our project page on GitHub.com.

  - Click the yellow bar that says "Compare & pull request".

  - Click the green "Create pull request" button.

3. Assign Reviewer: Select the Leader (Project Owner) as the "Reviewer".
4. Final Step: Wait for the leader to review and "Merge" your work into the main project.

---

## Professional Standards
1. Sync Regularly: Always run git pull origin main before starting any new work to avoid errors.

2. Commit Message Prefixes:

  - docs: (for documentation/report tasks)

  - feat: (for new code/features)

  - fix: (for fixing bugs or errors)

3. Issues: Regularly check the Issues tab on GitHub to see your assigned tasks.

4. Merge Conflicts: If you see an error saying "Merge Conflict", do not attempt to fix it alone. Message the leader immediately.