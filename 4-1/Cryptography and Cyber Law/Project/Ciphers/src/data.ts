import { CipherAlgorithm } from './types';

export const CIPHERS_DATA: CipherAlgorithm[] = [
  {
    id: 'caesar',
    name: 'Caesar Cipher',
    category: 'substitution',
    difficulty: 'Easy',
    description: 'One of the earliest and simplest known ciphers, shifting letters forward or backward by a fixed key distance.',
    howItWorks: 'To encrypt, shift each letter right by the Shift Value modulo 26. Spaces, digits, and symbols are preserved without change.',
    history: 'Named after Julius Caesar, who utilized it with a shift of 3 to safeguard Roman military orders. Today it is a classic teaching example for rotational substitution.',
    complexity: {
      time: 'O(N) - Single pass scan',
      space: 'O(N) - Output text array',
      keySpace: '25 usable keys'
    },
    keyLabel: 'Shift Offset (0 to 25)',
    keyPlaceholder: 'Enter shift amount (e.g. 3)',
    defaultKey: '3',
    keyType: 'number',
    keyValidation: (val) => {
      const num = parseInt(val, 10);
      if (isNaN(num) || num < 0 || num > 25) return 'Shift must be an integer between 0 and 25';
      return null;
    }
  },
  {
    id: 'monoalphabetic',
    name: 'Monoalphabetic Cipher',
    category: 'substitution',
    difficulty: 'Medium',
    description: 'A classical substitution cipher where each letter is replaced by the corresponding letter in a 26-letter scrambled alphabet.',
    howItWorks: 'Plaintext letters are substituted using a fixed 1:1 alphabet map. Each standard alphabet letter is replaced by the letter at the same position in the provided key.',
    history: 'Monoalphabetic substitution offered a larger key space than simple Caesar shift ciphers, but was eventually broken by frequency analysis.',
    complexity: {
      time: 'O(N) - Linear mapping lookup',
      space: 'O(N) - Output buffer',
      keySpace: '26! (approximately 4.03 × 10^26 variations)'
    },
    keyLabel: 'Scrambled Alphabet (26 unique letters)',
    keyPlaceholder: 'Enter 26 alphabet characters (e.g. QWERTYUIOPASDFGHJKLZXCVBNM)',
    defaultKey: 'QWERTYUIOPASDFGHJKLZXCVBNM',
    keyType: 'text',
    keyValidation: (val) => {
      const clean = val.replace(/[^a-zA-Z]/g, '').toUpperCase();
      if (clean.length !== 26) return 'Alphabet key must be exactly 26 letters long';
      const uniq = new Set(clean);
      if (uniq.size !== 26) return 'Alphabet key must contain 26 UNIQUE letters';
      return null;
    }
  },
  {
    id: 'playfair',
    name: 'Playfair Cipher',
    category: 'polyalphabetic',
    difficulty: 'Hard',
    description: 'A digraph cipher that encrypts text in letter pairs using a 5x5 key square.',
    howItWorks: 'A 5x5 grid is built from the key phrase, then plaintext is parsed into letter pairs. Letter pairs are transformed using row, column, or rectangle rules.',
    history: 'Invented in 1854 and used historically by militaries for quick manual encryption, Playfair was one of the first ciphers to encrypt letter pairs rather than single letters.',
    complexity: {
      time: 'O(N) - Digraph evaluation',
      space: 'O(1) auxiliary - static 5x5 grid',
      keySpace: '25! (over 1.5 × 10^25 grid permutations)'
    },
    keyLabel: 'Keyphrase (A-Z letters)',
    keyPlaceholder: 'Enter keyphrase (e.g. MONARCHY)',
    defaultKey: 'MONARCHY',
    keyType: 'text',
    keyValidation: (val) => {
      if (!val || !/^[a-zA-Z\s]+$/.test(val)) return 'Keyphrase must contain only letters and spaces';
      return null;
    }
  },
  {
    id: 'hill',
    name: 'Hill Cipher',
    category: 'polyalphabetic',
    difficulty: 'Hard',
    description: 'A 2x2 matrix cipher that encrypts plaintext digraphs through linear algebra modulo 26.',
    howItWorks: 'Plaintext letters are grouped in pairs and treated as numeric vectors. Each pair is multiplied by a 2x2 key matrix modulo 26 to produce ciphertext letters.',
    history: 'Introduced in 1929, the Hill cipher was the first polygraphic substitution cipher that leveraged linear algebra for stronger encryption.',
    complexity: {
      time: 'O(N) - Block matrix multiplication',
      space: 'O(N) - Output buffer',
      keySpace: '157,248 invertible 2x2 matrices modulo 26'
    },
    keyLabel: 'Keyphrase Matrix (4 letters)',
    keyPlaceholder: 'Enter a 4-letter matrix word (e.g. HELP)',
    defaultKey: 'HELP',
    keyType: 'text',
    keyValidation: (val) => {
      const clean = val.replace(/[^a-zA-Z]/g, '').toUpperCase();
      if (clean.length !== 4) return 'Hill key must be exactly 4 letters representing a 2x2 matrix';
      const a = clean[0].charCodeAt(0) - 65;
      const b = clean[1].charCodeAt(0) - 65;
      const c = clean[2].charCodeAt(0) - 65;
      const d = clean[3].charCodeAt(0) - 65;
      let det = (a * d - b * c) % 26;
      det = (det + 26) % 26;
      const isCoprime = det % 2 !== 0 && det % 13 !== 0;
      if (!isCoprime) return `Key matrix is singular/not invertible modulo 26 (Determinant ${det} lacks GCD=1 with 26). Try another word.`;
      return null;
    }
  },
  {
    id: 'one-time-pad',
    name: 'One-Time Pad Cipher',
    category: 'polyalphabetic',
    difficulty: 'Hard',
    description: 'A pad-based cipher that combines plaintext letters with a key pad using modular addition.',
    howItWorks: 'Plaintext letters are shifted by the corresponding pad key letters. Non-letter characters are preserved in place, and the pad repeats if shorter than the message.',
    history: 'One-time pads became known in the early 20th century as a theoretically unbreakable cipher when the key is truly random, secret, and never reused.',
    complexity: {
      time: 'O(N) - Linear text scan with key alignment',
      space: 'O(N) - Output buffer',
      keySpace: '26^L for a pad of length L'
    },
    keyLabel: 'Pad Key (A-Z letters)',
    keyPlaceholder: 'Enter pad key (e.g. XMCKL)',
    defaultKey: 'XMCKL',
    keyType: 'text',
    keyValidation: (val) => {
      if (!val || !/^[a-zA-Z]+$/.test(val)) return 'Pad key must contain only letters';
      return null;
    }
  }
];
