
# Credit Card Checker

A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. Those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary.

Credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55; and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow.

### *So, this program prompts the user for a credit card number and then reports whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.*

## Luhn’s Algorithm

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1.  Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2.  Add the sum to the sum of the digits that weren’t multiplied by 2.
3.  If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

#### **Let’s try an example with a Visa number: 4003600000000014.**

1. For the sake of discussion, let’s first close between brackets every other digit, starting with the number’s second-to-last digit:

[4] 0 [0] 3 [6] 0 [0] 0 [0] 0 [0] 0 [0] 0 [1] 4

2. Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

3. That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

4. Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

5. Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Correct, the last digit in that sum (20) is a 0, so the Visa number is legit! (for the example only).
