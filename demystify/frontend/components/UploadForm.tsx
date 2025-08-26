import React, { useRef } from 'react';

export default function UploadForm() {
  const fileInput = useRef<HTMLInputElement>(null);

  const handleUpload = async (e: React.FormEvent) => {
    e.preventDefault();
    // Handle file upload to backend
  };

  return (
    <form onSubmit={handleUpload}>
      <input type="file" accept=".pdf,.docx,.txt" ref={fileInput} />
      <button type="submit">Upload</button>
      <textarea placeholder="Or paste legal text here"></textarea>
    </form>
  );
}