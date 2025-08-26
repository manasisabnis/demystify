import UploadForm from '../components/UploadForm';
import Chatbot from '../components/Chatbot';
import SummaryDisplay from '../components/SummaryDisplay';
import History from '../components/History';


export default function Home() {
  return (
    <main>
      <h1>Demystify: Simplify Legal Documents</h1>
      <UploadForm />
      <SummaryDisplay />
      <Chatbot />
      <History />
    </main>
  );
}
