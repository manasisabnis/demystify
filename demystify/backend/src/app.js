const express = require('express');
const cors = require('cors');
const multer = require('multer');
const admin = require('firebase-admin');
const { extractText } = require('./services/extract');
const { summarize, explainClause, answerQuery } = require('./services/gcloud');
const { verifyToken } = require('./utils/security');

admin.initializeApp();
const app = express();
app.use(cors());
app.use(express.json());
const upload = multer({ dest: 'uploads/' });
app.use(verifyToken);

app.post('/api/documents/upload', upload.single('file'), async (req, res) => {
  try {
    const text = await extractText(req.file);
    const summary = await summarize(text);
    res.json({ summary });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

app.post('/api/documents/analyze', async (req, res) => {
  try {
    const { text } = req.body;
    const summary = await summarize(text);
    res.json({ summary });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

app.post('/api/ai/explain', async (req, res) => {
  try {
    const { clause } = req.body;
    const explanation = await explainClause(clause);
    res.json({ explanation });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

app.post('/api/ai/query', async (req, res) => {
  try {
    const { documentText, question } = req.body;
    const answer = await answerQuery(documentText, question);
    res.json({ answer });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

module.exports = app;