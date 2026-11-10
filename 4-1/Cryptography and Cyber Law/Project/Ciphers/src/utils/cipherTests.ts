import { TestCase, TestResult } from '../types';
import {
  caesarEncrypt,
  caesarDecrypt,
  playfairEncrypt,
  playfairDecrypt,
  monoalphabeticEncrypt,
  monoalphabeticDecrypt,
  hillEncrypt,
  hillDecrypt,
  oneTimePadEncrypt,
  oneTimePadDecrypt
} from './ciphers';

export const CIPHER_TEST_SUITE: TestCase[] = [
  {
    id: 't-caesar-1',
    name: 'Caesar Cipher: Standard Shift 3 (ROT3)',
    cipherId: 'caesar',
    input: 'HELLO WORLD',
    key: '3',
    expectedEncrypt: 'KHOOR ZRUOG',
    expectedDecrypt: 'HELLO WORLD'
  },
  {
    id: 't-caesar-2',
    name: 'Caesar Cipher: Circular Wrapping with Shift 25',
    cipherId: 'caesar',
    input: 'XYZ abc',
    key: '25',
    expectedEncrypt: 'WXY zab',
    expectedDecrypt: 'XYZ abc'
  },
  {
    id: 't-playfair-1',
    name: 'Playfair Cipher: Grid 5x5 Key alignment',
    cipherId: 'playfair',
    input: 'INSTRUMENTS',
    key: 'MONARCHY',
    expectedEncrypt: 'GATLMZCLRQAX',
    expectedDecrypt: 'INSTRUMENTSX'
  },
  {
    id: 't-mono-1',
    name: 'Monoalphabetic Cipher: Standard Scrambled Key',
    cipherId: 'monoalphabetic',
    input: 'HELLO WORLD',
    key: 'QWERTYUIOPASDFGHJKLZXCVBNM',
    expectedEncrypt: 'ITSSG VGKSR',
    expectedDecrypt: 'HELLO WORLD'
  },
  {
    id: 't-hill-1',
    name: 'Hill Cipher: 2x2 Invertible Matrix HELP',
    cipherId: 'hill',
    input: 'HELP',
    key: 'HELP',
    expectedEncrypt: 'NHHI',
    expectedDecrypt: 'HELP'
  },
  {
    id: 't-one-time-pad-1',
    name: 'One-Time Pad Cipher: Pad key XMCKL',
    cipherId: 'one-time-pad',
    input: 'HELLO',
    key: 'XMCKL',
    expectedEncrypt: 'EQNVZ',
    expectedDecrypt: 'HELLO'
  }
];

export function runCipherTests(): TestResult[] {
  return CIPHER_TEST_SUITE.map(tc => {
    let t0 = 0;
    let actualEncrypt = '';
    let encryptDurationMs = 0;

    let t1 = 0;
    let actualDecrypt = '';
    let decryptDurationMs = 0;

    let passed = false;
    let errorMessage = '';

    try {
      if (tc.cipherId === 'caesar') {
        const shiftInt = parseInt(tc.key, 10) || 0;
        t0 = performance.now();
        const resEnc = caesarEncrypt(tc.input, shiftInt);
        encryptDurationMs = performance.now() - t0;
        actualEncrypt = resEnc.outputText;

        t1 = performance.now();
        const resDec = caesarDecrypt(actualEncrypt, shiftInt);
        decryptDurationMs = performance.now() - t1;
        actualDecrypt = resDec.outputText;
      } else if (tc.cipherId === 'playfair') {
        t0 = performance.now();
        const resEnc = playfairEncrypt(tc.input, tc.key);
        encryptDurationMs = performance.now() - t0;
        actualEncrypt = resEnc.outputText;

        t1 = performance.now();
        const resDec = playfairDecrypt(actualEncrypt, tc.key);
        decryptDurationMs = performance.now() - t1;
        actualDecrypt = resDec.outputText;
      } else if (tc.cipherId === 'monoalphabetic') {
        t0 = performance.now();
        const resEnc = monoalphabeticEncrypt(tc.input, tc.key);
        encryptDurationMs = performance.now() - t0;
        actualEncrypt = resEnc.outputText;

        t1 = performance.now();
        const resDec = monoalphabeticDecrypt(actualEncrypt, tc.key);
        decryptDurationMs = performance.now() - t1;
        actualDecrypt = resDec.outputText;
      } else if (tc.cipherId === 'hill') {
        t0 = performance.now();
        const resEnc = hillEncrypt(tc.input, tc.key);
        encryptDurationMs = performance.now() - t0;
        actualEncrypt = resEnc.outputText;

        t1 = performance.now();
        const resDec = hillDecrypt(actualEncrypt, tc.key);
        decryptDurationMs = performance.now() - t1;
        actualDecrypt = resDec.outputText;
      } else if (tc.cipherId === 'one-time-pad') {
        t0 = performance.now();
        const resEnc = oneTimePadEncrypt(tc.input, tc.key);
        encryptDurationMs = performance.now() - t0;
        actualEncrypt = resEnc.outputText;

        t1 = performance.now();
        const resDec = oneTimePadDecrypt(actualEncrypt, tc.key);
        decryptDurationMs = performance.now() - t1;
        actualDecrypt = resDec.outputText;
      } else {
        throw new Error(`Test suite contains unsupported cipherId: ${tc.cipherId}`);
      }

      const encryptMatch = actualEncrypt === tc.expectedEncrypt;
      const decryptMatch = actualDecrypt === tc.expectedDecrypt;

      if (encryptMatch && decryptMatch) {
        passed = true;
      } else {
        const issues = [];
        if (!encryptMatch) issues.push(`Encrypt mismatch. Expected "${tc.expectedEncrypt}", got "${actualEncrypt}"`);
        if (!decryptMatch) issues.push(`Decrypt mismatch. Expected "${tc.expectedDecrypt}", got "${actualDecrypt}"`);
        errorMessage = issues.join('; ');
      }
    } catch (err: any) {
      passed = false;
      errorMessage = err?.message || 'Error occurred during cryptographic execution';
    }

    return {
      testCase: tc,
      passed,
      encryptDurationMs: parseFloat(encryptDurationMs.toFixed(3)),
      decryptDurationMs: parseFloat(decryptDurationMs.toFixed(3)),
      actualEncrypt,
      actualDecrypt,
      errorMessage: errorMessage || undefined
    };
  });
}
