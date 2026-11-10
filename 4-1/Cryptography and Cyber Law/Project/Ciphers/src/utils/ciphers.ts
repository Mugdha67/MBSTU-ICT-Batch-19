import { CipherResult, EncryptionStep, PlayfairDetails } from '../types';

// Helper: Normalize key text
export function cleanKeyText(key: string): string {
  return key.toUpperCase().replace(/[^A-Z]/g, '');
}

/** =========================================================================
 * 1. CAESAR CIPHER
 * ========================================================================= */
export function caesarEncrypt(text: string, shift: number): CipherResult {
  const steps: EncryptionStep[] = [];
  const normalizedShift = ((shift % 26) + 26) % 26;
  let outputText = '';

  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const codeBase = isUpper ? 65 : 97;
      const originalIndex = char.charCodeAt(0) - codeBase;
      const cipherIndex = (originalIndex + normalizedShift) % 26;
      const cipherChar = String.fromCharCode(codeBase + cipherIndex);
      
      outputText += cipherChar;
      steps.push({
        index: i,
        original: char,
        keyUsed: normalizedShift,
        calculation: `${originalIndex} + ${normalizedShift} ≡ ${cipherIndex} (mod 26)`,
        result: cipherChar
      });
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-alphabetic character: ignored',
        result: char
      });
    }
  }

  return { outputText, steps };
}

export function caesarDecrypt(text: string, shift: number): CipherResult {
  const steps: EncryptionStep[] = [];
  const normalizedShift = ((shift % 26) + 26) % 26;
  let outputText = '';

  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const codeBase = isUpper ? 65 : 97;
      const originalIndex = char.charCodeAt(0) - codeBase;
      const plainIndex = (originalIndex - normalizedShift + 26) % 26;
      const plainChar = String.fromCharCode(codeBase + plainIndex);
      
      outputText += plainChar;
      steps.push({
        index: i,
        original: char,
        keyUsed: normalizedShift,
        calculation: `${originalIndex} - ${normalizedShift} ≡ ${plainIndex} (mod 26)`,
        result: plainChar
      });
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-alphabetic character: ignored',
        result: char
      });
    }
  }

  return { outputText, steps };
}


// Legacy cipher implementations removed: only Caesar, Playfair, Monoalphabetic, Hill, and One-Time Pad remain.


/** =========================================================================
 * 6. PLAYFAIR CIPHER (SUPPORT INTERACTIVE 5x5 GRID)
 * ========================================================================= */
export function generatePlayfairGrid(key: string): string[][] {
  const cleanKey = cleanKeyText(key).replace(/J/g, 'I');
  const alphabet = 'ABCDEFGHIKLMNOPQRSTUVWXYZ'; // 'J' omitted
  const seen = new Set<string>();
  const list: string[] = [];

  // Add key letters
  for (const char of cleanKey) {
    if (!seen.has(char)) {
      seen.add(char);
      list.push(char);
    }
  }

  // Fill standard alphabet remainder
  for (const char of alphabet) {
    if (!seen.has(char)) {
      seen.add(char);
      list.push(char);
    }
  }

  // Construct 5x5 matrix
  const grid: string[][] = [];
  for (let i = 0; i < 5; i++) {
    grid.push(list.slice(i * 5, i * 5 + 5));
  }
  return grid;
}

// Find coordinate in playfair grid
export function findGridCoords(grid: string[][], char: string): [number, number] {
  const checkChar = char === 'J' ? 'I' : char;
  for (let r = 0; r < 5; r++) {
    for (let c = 0; c < 5; c++) {
      if (grid[r][c] === checkChar) {
        return [r, c];
      }
    }
  }
  return [0, 0];
}

// Prepare playfair text into digraph pairs
export function preparePlayfairPairs(text: string): [string, string][] {
  const cleaned = cleanKeyText(text).replace(/J/g, 'I');
  const pairs: [string, string][] = [];
  let i = 0;

  while (i < cleaned.length) {
    const char1 = cleaned[i];
    let char2 = '';

    if (i + 1 < cleaned.length) {
      const nextChar = cleaned[i + 1];
      if (char1 === nextChar) {
        char2 = 'X';
        i++; // step by 1 is safe, splits duplicates with X
      } else {
        char2 = nextChar;
        i += 2;
      }
    } else {
      char2 = 'X';
      i++;
    }
    pairs.push([char1, char2]);
  }

  return pairs;
}

export function playfairEncrypt(text: string, key: string): CipherResult {
  const grid = generatePlayfairGrid(key);
  const pairs = preparePlayfairPairs(text);
  const cipherPairs: [string, string][] = [];
  const rulesApplied: string[] = [];
  const steps: EncryptionStep[] = [];
  let outputText = '';

  for (let p = 0; p < pairs.length; p++) {
    const [c1, c2] = pairs[p];
    const [r1, col1] = findGridCoords(grid, c1);
    const [r2, col2] = findGridCoords(grid, c2);

    let rc1_res = '';
    let rc2_res = '';
    let rule = '';

    if (r1 === r2) {
      // Rule 1: Same row, shift right with wrapping
      rc1_res = grid[r1][(col1 + 1) % 5];
      rc2_res = grid[r2][(col2 + 1) % 5];
      rule = 'Row alignment: Shift right';
    } else if (col1 === col2) {
      // Rule 2: Same column, shift down with wrapping
      rc1_res = grid[(r1 + 1) % 5][col1];
      rc2_res = grid[(r2 + 1) % 5][col2];
      rule = 'Col alignment: Shift down';
    } else {
      // Rule 3: Rectangle, swap column indices
      rc1_res = grid[r1][col2];
      rc2_res = grid[r2][col1];
      rule = 'Rectangle: Swap columns';
    }

    cipherPairs.push([rc1_res, rc2_res]);
    rulesApplied.push(rule);
    outputText += rc1_res + rc2_res;

    steps.push({
      index: p,
      original: `${c1}${c2}`,
      calculation: `${rule} [(${r1},${col1}) & (${r2},${col2})]`,
      result: `${rc1_res}${rc2_res}`,
      highlightedIndices: [r1 * 5 + col1, r2 * 5 + col2]
    });
  }

  const details: PlayfairDetails = {
    grid,
    pairs,
    cipherPairs,
    rulesApplied
  };

  return {
    outputText,
    steps,
    meta: details
  };
}

function parseCipherTextPairs(text: string): [string, string][] {
  const cleaned = cleanKeyText(text).replace(/J/g, 'I');
  const pairs: [string, string][] = [];

  for (let i = 0; i < cleaned.length; i += 2) {
    const first = cleaned[i];
    const second = i + 1 < cleaned.length ? cleaned[i + 1] : 'X';
    pairs.push([first, second]);
  }

  return pairs;
}

export function playfairDecrypt(text: string, key: string): CipherResult {
  const grid = generatePlayfairGrid(key);
  const pairs = parseCipherTextPairs(text);
  const plainPairs: [string, string][] = [];
  const rulesApplied: string[] = [];
  const steps: EncryptionStep[] = [];
  let outputText = '';

  for (let p = 0; p < pairs.length; p++) {
    const [c1, c2] = pairs[p];
    const [r1, col1] = findGridCoords(grid, c1);
    const [r2, col2] = findGridCoords(grid, c2);

    let rc1_res = '';
    let rc2_res = '';
    let rule = '';

    if (r1 === r2) {
      rc1_res = grid[r1][(col1 - 1 + 5) % 5];
      rc2_res = grid[r2][(col2 - 1 + 5) % 5];
      rule = 'Row alignment: Shift left';
    } else if (col1 === col2) {
      rc1_res = grid[(r1 - 1 + 5) % 5][col1];
      rc2_res = grid[(r2 - 1 + 5) % 5][col2];
      rule = 'Col alignment: Shift up';
    } else {
      rc1_res = grid[r1][col2];
      rc2_res = grid[r2][col1];
      rule = 'Rectangle: Swap columns';
    }

    plainPairs.push([rc1_res, rc2_res]);
    rulesApplied.push(rule);
    outputText += rc1_res + rc2_res;

    steps.push({
      index: p,
      original: `${c1}${c2}`,
      calculation: `${rule} [(${r1},${col1}) & (${r2},${col2})]`,
      result: `${rc1_res}${rc2_res}`,
      highlightedIndices: [r1 * 5 + col1, r2 * 5 + col2]
    });
  }

  const details: PlayfairDetails = {
    grid,
    pairs,
    cipherPairs: plainPairs,
    rulesApplied
  };

  return {
    outputText,
    steps,
    meta: details
  };
}

export function oneTimePadEncrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = cleanKeyText(key);
  let outputText = '';
  let keyIndex = 0;

  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const codeBase = isUpper ? 65 : 97;
      const textVal = char.charCodeAt(0) - codeBase;
      const keyChar = cleanKey[keyIndex % cleanKey.length] || 'A';
      const keyVal = keyChar.charCodeAt(0) - 65;
      const cipherVal = (textVal + keyVal) % 26;
      const cipherChar = String.fromCharCode(codeBase + cipherVal);
      outputText += cipherChar;
      steps.push({
        index: i,
        original: char,
        keyUsed: keyChar,
        calculation: `${textVal} + ${keyVal} ≡ ${cipherVal} (mod 26)`,
        result: cipherChar
      });
      keyIndex++;
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-letter character preserved',
        result: char
      });
    }
  }

  return {
    outputText,
    steps,
    meta: {
      key: cleanKey,
      keyLength: cleanKey.length
    }
  };
}

export function oneTimePadDecrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = cleanKeyText(key);
  let outputText = '';
  let keyIndex = 0;

  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const codeBase = isUpper ? 65 : 97;
      const textVal = char.charCodeAt(0) - codeBase;
      const keyChar = cleanKey[keyIndex % cleanKey.length] || 'A';
      const keyVal = keyChar.charCodeAt(0) - 65;
      const plainVal = (textVal - keyVal + 26) % 26;
      const plainChar = String.fromCharCode(codeBase + plainVal);
      outputText += plainChar;
      steps.push({
        index: i,
        original: char,
        keyUsed: keyChar,
        calculation: `${textVal} - ${keyVal} ≡ ${plainVal} (mod 26)`,
        result: plainChar
      });
      keyIndex++;
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-letter character preserved',
        result: char
      });
    }
  }

  return {
    outputText,
    steps,
    meta: {
      key: cleanKey,
      keyLength: cleanKey.length
    }
  };
}


/** =========================================================================
 * 7. MONOALPHABETIC CIPHER
 * ========================================================================= */
export function monoalphabeticEncrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = key.toUpperCase().replace(/[^A-Z]/g, '');
  const standardAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  
  // If key is invalid (not size 26 or duplicates), default to identity map
  const isKeyValid = cleanKey.length === 26 && new Set(cleanKey).size === 26;
  const alphabetMap = isKeyValid ? cleanKey : standardAlphabet;
  
  let outputText = '';
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const basisCode = isUpper ? 65 : 97;
      const originalIdx = char.charCodeAt(0) - basisCode;
      
      const targetCharUpper = alphabetMap[originalIdx];
      const targetChar = isUpper ? targetCharUpper : targetCharUpper.toLowerCase();
      
      outputText += targetChar;
      steps.push({
        index: i,
        original: char,
        calculation: `'${char}' (${originalIdx}) mapped to index ${originalIdx} of key ➔ '${targetChar}'`,
        result: targetChar,
        highlightedIndices: [originalIdx]
      });
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-alphabetic character: ignored',
        result: char
      });
    }
  }
  
  return {
    outputText,
    steps,
    meta: {
      alphabetMap,
      standardAlphabet,
      isKeyValid
    }
  };
}

export function monoalphabeticDecrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = key.toUpperCase().replace(/[^A-Z]/g, '');
  const standardAlphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  
  const isKeyValid = cleanKey.length === 26 && new Set(cleanKey).size === 26;
  const alphabetMap = isKeyValid ? cleanKey : standardAlphabet;
  
  // Generate reverse map
  const reverseMap: { [char: string]: number } = {};
  for (let i = 0; i < alphabetMap.length; i++) {
    reverseMap[alphabetMap[i]] = i;
  }
  
  let outputText = '';
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const isUpper = char === char.toUpperCase();
      const targetCharUpper = char.toUpperCase();
      const originalIdx = reverseMap[targetCharUpper] !== undefined ? reverseMap[targetCharUpper] : (targetCharUpper.charCodeAt(0) - 65);
      
      const sourceCharUpper = standardAlphabet[originalIdx];
      const sourceChar = isUpper ? sourceCharUpper : sourceCharUpper.toLowerCase();
      
      outputText += sourceChar;
      steps.push({
        index: i,
        original: char,
        calculation: `'${char}' found at key position ${originalIdx} ➔ standard mapped to '${sourceChar}'`,
        result: sourceChar,
        highlightedIndices: [originalIdx]
      });
    } else {
      outputText += char;
      steps.push({
        index: i,
        original: char,
        calculation: 'Non-alphabetic character: ignored',
        result: char
      });
    }
  }
  
  return {
    outputText,
    steps,
    meta: {
      alphabetMap,
      standardAlphabet,
      isKeyValid
    }
  };
}

/** =========================================================================
 * 8. HILL CIPHER (2x2 Matrix)
 * ========================================================================= */
export function hillEncrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = cleanKeyText(key);
  
  // Ensure we have a valid 4-character key representing an invertible 2x2 matrix
  // Default to "HELP" if invalid
  let matKey = cleanKey.length >= 4 ? cleanKey.slice(0, 4) : 'HELP';
  let a = matKey[0].charCodeAt(0) - 65;
  let b = matKey[1].charCodeAt(0) - 65;
  let c = matKey[2].charCodeAt(0) - 65;
  let d = matKey[3].charCodeAt(0) - 65;
  
  let det = (a * d - b * c) % 26;
  det = (det + 26) % 26;
  
  // If not invertible, fallback to default HELP
  let isKeyInvertible = det % 2 !== 0 && det % 13 !== 0;
  if (!isKeyInvertible) {
    matKey = 'HELP';
    a = 7; b = 4; c = 11; d = 15;
    det = 9;
  }
  
  // Extract all letters from input to process block-wise
  const letterIndices: number[] = [];
  const letters: string[] = [];
  const letterIsUpper: boolean[] = [];
  
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      letterIndices.push(i);
      letters.push(char.toUpperCase());
      letterIsUpper.push(char === char.toUpperCase());
    }
  }
  
  // If odd length, append 'X'
  const originalLetterCount = letters.length;
  if (letters.length % 2 !== 0) {
    letters.push('X');
    letterIsUpper.push(true); // default uppercase for pad
  }
  
  const encryptedLetters: string[] = [];
  
  // Perform matrix multiplication in blocks of 2
  for (let i = 0; i < letters.length; i += 2) {
    const x = letters[i].charCodeAt(0) - 65;
    const y = letters[i + 1].charCodeAt(0) - 65;
    
    const nx = (a * x + b * y) % 26;
    const ny = (c * x + d * y) % 26;
    
    const char1 = String.fromCharCode(65 + nx);
    const char2 = String.fromCharCode(65 + ny);
    
    encryptedLetters.push(char1);
    encryptedLetters.push(char2);
    
    steps.push({
      index: i / 2,
      original: `${letters[i]}${letters[i + 1]}`,
      calculation: `[${a} ${b}; ${c} ${d}] * [${x}; ${y}] ≡ [(${a}*${x} + ${b}*${y}) mod 26; (${c}*${x} + ${d}*${y}) mod 26] ≡ [${nx}; ${ny}] ➔ ${char1}${char2}`,
      result: `${char1}${char2}`
    });
  }
  
  // Reconstruct output text: restore spacing and symbols, but letters are replaced
  let outputText = '';
  let letterPtr = 0;
  
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      const encChar = encryptedLetters[letterPtr];
      const isUpper = letterIsUpper[letterPtr];
      outputText += isUpper ? encChar : encChar.toLowerCase();
      letterPtr++;
    } else {
      outputText += char;
    }
  }
  
  // If we had a padded 'X', append to output if requested, or keep it consistent
  if (letters.length > originalLetterCount) {
    const lastEncChar = encryptedLetters[encryptedLetters.length - 1];
    outputText += lastEncChar; // padded letter
  }
  
  return {
    outputText,
    steps,
    meta: {
      matrix: [[a, b], [c, d]],
      matKey,
      det,
      isKeyInvertible
    }
  };
}

export function hillDecrypt(text: string, key: string): CipherResult {
  const steps: EncryptionStep[] = [];
  const cleanKey = cleanKeyText(key);
  
  let matKey = cleanKey.length >= 4 ? cleanKey.slice(0, 4) : 'HELP';
  let a = matKey[0].charCodeAt(0) - 65;
  let b = matKey[1].charCodeAt(0) - 65;
  let c = matKey[2].charCodeAt(0) - 65;
  let d = matKey[3].charCodeAt(0) - 65;
  
  let det = (a * d - b * c) % 26;
  det = (det + 26) % 26;
  
  let isKeyInvertible = det % 2 !== 0 && det % 13 !== 0;
  if (!isKeyInvertible) {
    matKey = 'HELP';
    a = 7; b = 4; c = 11; d = 15;
    det = 9;
  }
  
  // Find modular multiplicative inverse of determinant modulo 26
  let detInv = 1;
  for (let i = 1; i < 26; i++) {
    if ((det * i) % 26 === 1) {
      detInv = i;
      break;
    }
  }
  
  // Inverse matrix modulo 26: detInv * adjugate [d, -b; -c, a]
  const a_inv = (d * detInv) % 26;
  const b_inv = (((-b + 26) % 26) * detInv) % 26;
  const c_inv = (((-c + 26) % 26) * detInv) % 26;
  const d_inv = (a * detInv) % 26;
  
  // Extract letters
  const letterIndices: number[] = [];
  const letters: string[] = [];
  const letterIsUpper: boolean[] = [];
  
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      letterIndices.push(i);
      letters.push(char.toUpperCase());
      letterIsUpper.push(char === char.toUpperCase());
    }
  }
  
  if (letters.length % 2 !== 0) {
    letters.push('X');
    letterIsUpper.push(true);
  }
  
  const decryptedLetters: string[] = [];
  for (let i = 0; i < letters.length; i += 2) {
    const x = letters[i].charCodeAt(0) - 65;
    const y = letters[i + 1].charCodeAt(0) - 65;
    
    const nx = (a_inv * x + b_inv * y) % 26;
    const ny = (c_inv * x + d_inv * y) % 26;
    
    const char1 = String.fromCharCode(65 + nx);
    const char2 = String.fromCharCode(65 + ny);
    
    decryptedLetters.push(char1);
    decryptedLetters.push(char2);
    
    steps.push({
      index: i / 2,
      original: `${letters[i]}${letters[i + 1]}`,
      calculation: `[${a_inv} ${b_inv}; ${c_inv} ${d_inv}] * [${x}; ${y}] ≡ [(${a_inv}*${x} + ${b_inv}*${y}) mod 26; (${c_inv}*${x} + ${d_inv}*${y}) mod 26] ≡ [${nx}; ${ny}] ➔ ${char1}${char2}`,
      result: `${char1}${char2}`
    });
  }
  
  let outputText = '';
  let letterPtr = 0;
  
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (/[a-zA-Z]/.test(char)) {
      if (letterPtr < decryptedLetters.length) {
        const decChar = decryptedLetters[letterPtr];
        const isUpper = letterIsUpper[letterPtr];
        outputText += isUpper ? decChar : decChar.toLowerCase();
        letterPtr++;
      }
    } else {
      outputText += char;
    }
  }
  
  if (letters.length > letterIndices.length && letterPtr < decryptedLetters.length) {
    outputText += decryptedLetters[letterPtr];
  }
  
  return {
    outputText,
    steps,
    meta: {
      matrix: [[a_inv, b_inv], [c_inv, d_inv]],
      matKey,
      det,
      detInv,
      isKeyInvertible
    }
  };
}
