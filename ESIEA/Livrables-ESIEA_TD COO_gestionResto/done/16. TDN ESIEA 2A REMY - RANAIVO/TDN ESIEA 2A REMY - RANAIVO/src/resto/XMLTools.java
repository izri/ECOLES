package resto;


import java.beans.PersistenceDelegate;
import java.beans.XMLDecoder;
import java.beans.XMLEncoder;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class XMLTools {
	private XMLTools() {}
	/**
	 * Serialisation d'un objet dans un fichier
	 * @param object objet a serialiser
	 * @param filename chemin du fichier
	 */
	public static void encodeToFile(Object object, String fileName) throws FileNotFoundException, IOException {
		// ouverture de l'encodeur vers le fichier
		XMLEncoder encoder = new XMLEncoder(new FileOutputStream(fileName));
		try {
			// serialisation de l'objet
			encoder.writeObject(object);
			encoder.flush();
		} finally {
			// fermeture de l'encodeur
			encoder.close();
		}
	}

	public static Object decodeFromFile(String fileName) throws FileNotFoundException, IOException {
		Object object = null;
		// ouverture de decodeur
		XMLDecoder decoder = new XMLDecoder(new FileInputStream(fileName));
		try {
			// deserialisation de l'objet
			object = decoder.readObject();
		} finally {
			// fermeture du decodeur
			decoder.close();
		}
		return object;
	}
}
