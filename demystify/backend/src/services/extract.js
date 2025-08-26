const pdfParse = require('pdf-parse');
const mammoth = require('mammoth');
const fs = require('fs');

async function extractText(file) {
  if (file.mimetype === 'application/pdf') {
    return (await pdfParse(fs.readFileSync(file.path))).text;
  }
  if (file.mimetype === 'application/vnd.openxmlformats-officedocument.wordprocessingml.document') {
    return (await mammoth.extractRawText({ path: file.path })).value;
  }
  if (file.mimetype === 'text/plain') {
    return fs.readFileSync(file.path, 'utf8');
  }
  throw new Error('Unsupported file type');
}

module.exports = { extractText };