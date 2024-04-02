# Assembly Mini Board

This mini board aims to asses your understanding of C code before moving on to the Assembly section.
It should not take longer than an hour to complete.

Please discuss your thought process out loud with those evaluating this assessment -- we are interested in seeing how you think and problem solve, and are excited to watch you find the solutions.

You are allowed to ask questions while completing this, however we may request that you continue problem solving on your own before giving more guidance.

You are welcome to draw things out on the whiteboard, a piece of paper, or type in this document in order to organize your thoughts while completing this assessment.

## Password Manager

The `hash.c` and `hash.h` files contain incomplete code for a simple password manager that uses salted hashes. 

It's a good idea to store password hashes instead of actual passwords to prevent passwords from being revealed in the event of a data leak. When a user logs in, their password is hashed and the output of the hash function is compared with a stored value.

"Salting" a hash refers to the process of adding random data, known as a "salt," to the input of a hash function before hashing. The resulting hash value includes both the original password and the salt. This further increases security by protecting against rainbow table attacks, where common password hashes are precomputed and checked against a table. Furthermore, the use of a salt means that users will have different hashes even if their passwords are the same.

The `hash.c` file contains several TODO statements that need to be completed. You should only need to edit the `hash.c` and `hash.h` files to complete this challenge. 

