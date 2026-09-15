# 🔐 ICT 4115: Cryptography and Cyber Law — HANDWRITTEN ASSIGNMENT

**Mawlana Bhashani Science and Technology University, Tangail**
Department of Information and Communication Technology
B.Sc. in ICT, MBSTU

| | |
|---|---|
| 🏆 **Total Questions** | 40 (5 per topic area, 8 topic areas) |
| 📝 **Format** | Each question is standalone (no sub-parts) with marks shown at the end |
| 🎓 **Level** | B.Sc standard — emphasis on derivation, proof, protocol design, and critical analysis rather than plug-and-chug computation |

> Handwritten Assignment, To be Submitted via GitHub as PDF. Develop an excel file and include Assignment URL beside student Roll Number and send me two days before your final exam. The marking style used here may not exactly match the marking scheme used in the final examination. The marks shown here should be considered at half weight for final exam preparation. Please prepare accordingly.

---

## 📚 Table of Contents

1. [Abstract Algebra and Number Theory Foundations of Cryptography (Q1–Q5)](#number-theory-foundations-of-cryptography)
2. [Modular Arithmetic & the Chinese Remainder Theorem (Q6–Q10)](#modular-arithmetic--the-chinese-remainder-theorem)
3. [Classical & Symmetric Block Ciphers (Q11–Q15)](#classical--symmetric-block-ciphers)
4. [Inside AES: Modes, Transformations & Side Channels (Q16–Q20)](#inside-aes-modes-transformations--side-channels)
5. [RSA Signatures, IPSec & Diffie–Hellman (Q21–Q25)](#rsa-signatures-ipsec--diffiehellman)
6. [ElGamal Signatures & Elliptic Curve Cryptography (Q26–Q30)](#elgamal-signatures--elliptic-curve-cryptography)
7. [Hash Functions & Lattice-Based (Post-Quantum) Cryptography (Q31–Q35)](#hash-functions--lattice-based-post-quantum-cryptography)
8. [Applied Protocol Security: Kerberos, MAC, TLS & IoT (Q36–Q40)](#applied-protocol-security-kerberos-mac-tls--iot)

---

## Abstract Algebra and Number Theory Foundations of Cryptography

> 🎯 **Use case:** RSA and Diffie–Hellman key generation both rest on primality testing and finite-field/group structure. A flawed primality test — or a misunderstanding of when Z_n is a field versus merely a ring — can silently break a cryptosystem.

**1.** Prove Fermat's Little Theorem from group-theoretic first principles, then explain how it motivates the Miller–Rabin probabilistic primality test. Apply the test (base $a = 2$) to $n = 561$ and explain why $561$ is a Carmichael number that fools the simpler Fermat test. *(6 marks)*

**2.** Prove that ${Z}$, under addition and multiplication modulo $n$, is a field if and only if $n$ is prime. Illustrate your proof by contrasting the multiplicative structure of $Z_{11}$ (prime modulus) with $Z_{12}$ (composite modulus). *(5 marks)*

**3.** Construct $GF(2^3)$ using the irreducible polynomial $x^3 + x + 1$ over $GF(2)$. Build the multiplication table for a generator element $\alpha$, and determine whether the multiplicative group $GF(2^3)^*$ is cyclic. *(6 marks)*

**4.** Derive the time complexity of modular exponentiation via square-and-multiply. Compute $7^{560} \bmod 561$ step by step, and interpret the result in light of $561$ being a Carmichael number. *(5 marks)*

**5.** Compare deterministic (AKS) and probabilistic (Miller–Rabin) primality testing in terms of asymptotic complexity, error probability, and practical relevance to RSA key generation at 2048-bit and 4096-bit key sizes. *(4 marks)*

---

## Modular Arithmetic & the Chinese Remainder Theorem

> 🎯 **Use case:** CRT-based optimization makes RSA private-key operations roughly 4× faster and is built into nearly every production RSA library (OpenSSL, etc.) — but a faulty CRT implementation was also the basis of the real-world Bellcore fault-injection attack on RSA signatures.

**6.** Derive the Extended Euclidean Algorithm formally (as a sequence of linear combinations), then use it to compute $\gcd(240, 46)$ together with the Bézout coefficients $x, y$ such that $240x + 46y = \gcd(240,46)$. *(5 marks)*

**7.** State and prove the Chinese Remainder Theorem (existence and uniqueness) for pairwise coprime moduli. Apply it to solve:
$$x \equiv 2 \pmod 3, \quad x \equiv 3 \pmod 5, \quad x \equiv 4 \pmod 7, \quad x \equiv 5 \pmod{11}$$ *(6 marks)*

**8.** Derive the CRT-based RSA decryption/signing optimization from first principles (computing $d_P$, $d_Q$, and $q_{\text{inv}}$), and demonstrate the ~4× speed-up with a fully worked numerical example using small primes $p, q$. *(6 marks)*

**9.** Explain the Bellcore fault-injection attack on RSA-CRT signatures: how a single faulty modular computation during signing leaks a factor of $n$, and what countermeasures (e.g., signature verification before release) prevent it. *(5 marks)*

**10.** Compute a modular inverse using both the Extended Euclidean Algorithm and Fermat's-Little-Theorem-based exponentiation (for a prime modulus), and discuss the trade-offs between the two approaches for large moduli. *(4 marks)*

---

## Classical & Symmetric Block Ciphers

> 🎯 **Use case:** Playfair was genuine military-grade cryptography before computers existed, while the Feistel structure underlying DES is the direct ancestor of nearly every modern block-cipher design.

**11.** Design and fully execute a Playfair cipher encryption and decryption of a phrase of your choosing (minimum 16 letters) with a keyword of your choosing. Present the complete $5 \times 5$ key matrix as a table, and show every digraph substitution step. *(6 marks)*

**12.** Critically analyze the structural weaknesses of the Playfair cipher against digraph frequency analysis, and explain why it remains vulnerable to known-plaintext attacks despite being far stronger than monoalphabetic substitution. *(5 marks)*

**13.** Derive and trace **two full rounds** of a simplified Feistel-structured cipher (DES-like), showing $L_0, R_0 \to L_1, R_1 \to L_2, R_2$ symbolically, then with the numeric values $L_0 = \texttt{0xAAAAAAAA}$, $R_0 = \texttt{0xF0F0F0F0}$, $K_1 = \texttt{0x0F0F0F0F}$, $K_2 = \texttt{0x33333333}$, using XOR as the round function. *(6 marks)*

**14.** Formally define the *avalanche effect* in block ciphers. Using a toy 8-bit substitution–permutation network of your own construction, demonstrate how flipping a single input bit changes at least half the output bits, and explain why this property is essential for cryptographic security. *(5 marks)*

**15.** Evaluate the brute-force resistance of an 8-character alphanumeric password (62-character alphabet) versus a 6-digit PIN, under a modern GPU cracking rate of $10^9$ guesses/second. Compute worst-case and expected-case cracking times for both, and discuss the implications for password policy design. *(4 marks)*

---

## Inside AES: Modes, Transformations & Side Channels

> 🎯 **Use case:** Choosing the wrong AES mode is a real vulnerability class — mode selection determines whether a single bit error or IV reuse corrupts one block or cascades through an entire message, which is why it is a critical decision in TLS and disk encryption.

**16.** Compare the error-propagation and parallelizability characteristics of ECB, CBC, CFB, OFB, and CTR modes using a labelled diagram for each. Recommend the most suitable mode for (a) encrypting a live video stream over a lossy network and (b) encrypting a static disk image, with justification. *(6 marks)*

| Mode | Parallel encryption | Parallel decryption | Error propagation on bit-flip | Requires unique IV/nonce |
|---|---|---|---|---|
| ECB | Yes | Yes | Single block only (but reveals patterns) | No |
| CBC | No | Yes | Corrupts current + next block | Yes |
| CFB | No | Yes | Corrupts current + next block | Yes |
| OFB | No | No | Single bit only | Yes (never reused) |
| CTR | Yes | Yes | Single bit only | Yes (never reused) |

**17.** Using the partial AES S-box below, perform the SubBytes transformation on the state word $[\texttt{0x23}, \texttt{0xA7}, \texttt{0x4C}, \texttt{0x19}]$, then apply ShiftRows to a $4\times4$ state matrix that has this word as its first row (fill remaining rows with $\texttt{0x00}$ for the purpose of the exercise). Report the resulting matrix. *(6 marks)*

| Row ↓ / Col → | 3 | 4 | 7 | 9 | A | C |
|---|---|---|---|---|---|---|
| **1** | `6D` |  |  | `C6` |  |  |
| **2** | `D4` |  |  |  |  |  |
| **4** |  | `A1` |  |  |  | `2E` |
| **A** |  |  | `63` |  | `D2` |  |

**18.** Derive the AES-128 Rijndael key schedule and compute the first **two** round keys ($K_1$, $K_2$) from a given 128-bit cipher key of your choosing, showing the RotWord, SubWord, and Rcon steps explicitly. *(6 marks)*

**19.** Explain the MixColumns transformation as polynomial multiplication over $GF(2^8)$ modulo $x^8+x^4+x^3+x+1$. Work through the full multiplication of one input column by the fixed MixColumns matrix, showing the $GF(2^8)$ arithmetic for each byte. *(5 marks)*

**20.** Critically evaluate AES's resistance to side-channel attacks, specifically timing analysis (e.g., cache-timing attacks on table-based S-box implementations) and differential power analysis. Describe at least two concrete countermeasures (e.g., constant-time S-box, masking) and their performance trade-offs. *(4 marks)*

---

## RSA Signatures, IPSec & Diffie–Hellman

> 🎯 **Use case:** RSA signatures verify software updates and TLS certificates, IPSec overhead calculations determine VPN throughput budgets in enterprise networks, and Diffie–Hellman lets two strangers over an insecure channel agree on a shared secret without ever transmitting it.

**21.** Derive the RSA key-generation, encryption, and decryption procedures from Euler's Theorem, and prove correctness of decryption (i.e., that $(M^e)^d \equiv M \pmod n$) for the general case, including the case $\gcd(M,n) \ne 1$. *(6 marks)*

**22.** Given primes $p = 11$, $q = 13$, generate a full RSA keypair (choosing a valid public exponent $e$), then sign a message hash $H(M) = 23$ and verify the signature, showing all intermediate modular exponentiation steps. *(6 marks)*

**23.** Derive a general formula for IPSec ESP overhead percentage in tunnel mode as a function of payload size, header size, authentication-data size, and padding, then evaluate it for a 1200-byte payload with an 8-byte ESP header, 16 bytes of authentication data, and 2 bytes of padding. Discuss how this overhead scales for small IoT-sized packets versus large payloads. *(5 marks)*

**24.** Execute a full Diffie–Hellman key exchange with $p = 23$, $g = 5$, private keys $a = 6$ (Aleya) and $b = 15$ (Badol), confirming both parties derive the same shared secret. Then explain the man-in-the-middle vulnerability of unauthenticated DH and describe how an authenticated variant (e.g., the Station-to-Station protocol) mitigates it. *(6 marks)*

**25.** Compare the computational cost of establishing a shared key via RSA key transport versus Diffie–Hellman key agreement at an equivalent security level (e.g., 3072-bit RSA/DH versus 256-bit ECDH). Discuss why forward secrecy favors (EC)DHE over RSA key transport in modern TLS. *(4 marks)*

---

## ElGamal Signatures & Elliptic Curve Cryptography

> 🎯 **Use case:** ElGamal signatures underpin DSA, the U.S. federal digital signature standard, while elliptic-curve arithmetic is the backbone of ECDSA — the exact signature scheme securing Bitcoin transactions and most modern TLS handshakes.

**26.** In an ElGamal scheme with $p = 467$, $g = 2$, private key $x = 127$, message hash $H(M) = 100$, and nonce $k = 213$ (with $\gcd(k, p-1)=1$): compute the public key, generate the signature $(r,s)$, and verify it. *(6 marks)*

**27.** Prove algebraically that the ElGamal signature verification equation $g^{H(M)} \equiv y^r r^s \pmod p$ holds for a correctly generated signature, starting from the definition $s \equiv k^{-1}(H(M) - xr) \pmod{p-1}$. *(5 marks)*

**28.** On the elliptic curve $y^2 \equiv x^3 + x + 1 \pmod{23}$: verify that $P = (3,10)$ lies on the curve, compute $2P$ via point doubling, and compute $P + Q$ for $Q = (9,7)$, showing the full modular-arithmetic derivation of the slope in each case. *(6 marks)*

**29.** On the curve $y^2 \equiv x^3 + 7x + 10 \pmod{37}$ with base point $G = (2,5)$ of order $n = 19$ and private key $d = 9$: compute the public key $Q = dG$, generate an ECDSA signature $(r,s)$ for $H(M) = 8$ using nonce $k = 3$, and verify it against $Q$. *(6 marks)*

**30.** Compare the key-size security equivalence between RSA, ElGamal, and ECC (e.g., 256-bit ECC ≈ 3072-bit RSA/ElGamal at the ~128-bit security level), and explain why ECC is preferred for resource-constrained devices such as smart cards and IoT sensors. *(4 marks)*

---

## Hash Functions & Lattice-Based (Post-Quantum) Cryptography

> 🎯 **Use case:** SHA-256 is what makes Git commits and Bitcoin blocks tamper-evident, while lattice problems like SVP and SIVP are the hard mathematical problems behind NIST's newly standardized post-quantum algorithms (e.g., CRYSTALS-Kyber), designed to remain secure against quantum computers.

**31.** Formally define preimage resistance, second-preimage resistance, and collision resistance for a cryptographic hash function. Derive the birthday-attack complexity ($\approx 2^{n/2}$) for finding a collision in an $n$-bit hash, and explain why this motivates 256-bit (rather than 128-bit) output lengths for modern hash functions. *(6 marks)*

**32.** Trace the Merkle–Damgård construction with a diagram showing message blocks, compression function calls, and chaining variables. Explain the length-extension attack that this construction is vulnerable to, and how HMAC and SHA-3 (sponge construction) avoid it. *(6 marks)*

**33.** Explain the high-level internal structure of the SHA-256 compression function — message schedule expansion, the eight working variables, and the round function — using a labelled block diagram. You are not required to reproduce the exact bitwise logic, but must correctly identify each stage's role. *(5 marks)*

**34.** Formally define the Shortest Vector Problem (SVP) and the Shortest Independent Vectors Problem (SIVP) in lattice theory, and explain why both are believed to remain hard even for quantum computers (i.e., are not known to be solvable by Shor's algorithm). *(5 marks)*

**35.** Explain the core idea behind CRYSTALS-Kyber's Module-Learning-With-Errors (Module-LWE) key encapsulation mechanism, including how "noise" is used to hide the secret, and why this construction resists both classical and quantum attacks. *(5 marks)*

---

## Applied Protocol Security: Kerberos, MAC, TLS & IoT

> 🎯 **Use case:** These scenarios mirror real infrastructure decisions: Kerberos ticket lifetimes control single-sign-on session security in enterprise networks, MACs guarantee message integrity in banking transactions, TLS session-key derivation secures every HTTPS connection, and IoT bandwidth budgeting is essential for low-power sensor networks.

**36.** Diagram and explain the full Kerberos authentication protocol, covering the Authentication Server (AS) exchange, Ticket-Granting Server (TGS) exchange, and Client–Server (CS) exchange. Include how session keys and ticket lifetimes are established and why the TGT avoids repeated password transmission. *(6 marks)*

```
Client            AS                TGS               Service (S)
  |--(1) ID_C, ID_TGS------------->|                    |
  |<-(2) {K_c,tgs}Kc, TGT-----------|                    |
  |--(3) Authenticator, TGT-------------------------->|  |
  |<-(4) {K_c,s}Kc,tgs, Ticket_S----------------------|  |
  |--(5) Authenticator, Ticket_S------------------------------------>|
  |<-(6) {timestamp+1}Kc,s---------------------------------------------|
```

**37.** Explain why a plain hash-based MAC (i.e., $H(K \| M)$) is vulnerable to a length-extension attack, and derive how HMAC's nested construction $H(K \oplus opad \,\|\, H(K \oplus ipad \,\|\, M))$ eliminates this vulnerability. Illustrate with a small worked (simplified numeric) MAC example. *(5 marks)*

**38.** Diagram the TLS 1.3 handshake (ClientHello/ServerHello with key shares, encrypted extensions, Finished messages), and explain how the session keys are derived via HKDF from the (EC)DHE shared secret. Compare this against the TLS 1.2 handshake in terms of round-trip count and forward secrecy. *(6 marks)*

**39.** Design a bandwidth and duty-cycle budget for an IoT sensor network in which each node transmits a 1200-byte packet once per minute over a LPWAN technology of your choosing (e.g., LoRaWAN). Compute the total data volume per node per day (in bytes and KB), and discuss regulatory duty-cycle constraints (e.g., 1% airtime limits) that could affect this design. *(5 marks)*

**40.** Critically assess a lightweight cryptographic standard suitable for resource-constrained IoT devices (e.g., NIST's Ascon, selected as the lightweight cryptography standard) against AES-128 in terms of memory footprint, energy consumption, and side-channel resistance. Recommend which is more appropriate for a battery-powered sensor with < 10 KB of RAM. *(4 marks)*

---
