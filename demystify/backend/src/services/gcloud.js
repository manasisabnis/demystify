const { VertexAI } = require('@google-cloud/vertexai');
const vertexAi = new VertexAI({ project: process.env.GCLOUD_PROJECT });

async function summarize(text) {
  const response = await vertexAi.generateText({
    prompt: `Summarize this legal document in plain English:\n${text}`,
    model: 'text-bison',
  });
  return response.candidates[0].output;
}

async function explainClause(clause) {
  const response = await vertexAi.generateText({
    prompt: `Explain this legal clause in simple terms:\n${clause}`,
    model: 'text-bison',
  });
  return response.candidates[0].output;
}

async function answerQuery(documentText, question) {
  const response = await vertexAi.generateText({
    prompt: `Given the following legal document:\n${documentText}\nAnswer this question: ${question}`,
    model: 'text-bison',
  });
  return response.candidates[0].output;
}

module.exports = { summarize, explainClause, answerQuery };