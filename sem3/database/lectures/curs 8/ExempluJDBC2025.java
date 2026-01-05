import java.sql.*; //API JDBC

public class ExempluJDBC2025 {

	public static void main(String[] args) {
		//creez stringul de conexiune
		String connURL = "jdbc:sqlserver://"
				+ "DESKTOP-U7HDUM5:1433;"
				+ "instanceName=SQLEXPRESS;"
				+ "database=People;"
				+ "integratedSecurity=true;";
		ResultSet rs = null;
		//creez conexiunea cu BD
		try (Connection con=DriverManager.getConnection(connURL);
				Statement stmt = con.createStatement()){
			System.out.println("Conexiune!");
			//SELECT
			/*
			String selectSQL = "SELECT * from Persoane";
			rs = stmt.executeQuery(selectSQL);
			while (rs.next()) {
				System.out.println(rs.getString(1)+" "
						+rs.getString(2)+" "+rs.getString(3)+" "+
						rs.getString(4));
			}
			*/
			//INSERT
			/*
			String insertSQL = "insert into persoane values(21,'Lazar','Anna','Cluj-Napoca')";
			int nr = stmt.executeUpdate(insertSQL);
			System.out.println("S-au introdus "+nr+"inregistrari");
			*/
			
			//UPDATE
			/*
			String updateSLQ = "update Persoane set Localitate='Sibiu' where id=21";
			int nr = stmt.executeUpdate(updateSLQ);
			System.out.println("Numarul de inregistrari updatate: "+nr);
			*/
			
			//DELETE
			/*String deleteSQL = "delete from Persoane where id=21";
			int nr = stmt.executeUpdate(deleteSQL);
			System.out.println("Numarul de inregistrari sterse: "+nr);
			*/
			
			//CREATE
			String createSQL = "create table Client(id int primary key,"
					+ " nume varchar(50), preunume varchar(50))";
			stmt.executeUpdate(createSQL);
			
		}catch (SQLException e) {
			e.printStackTrace();
		}
	}
	public static void modifLocalitate(String[] nume, String[] localitate) throws SQLException{
		//creez stringul de conexiune
				String connURL = "jdbc:sqlserver://"
						+ "DESKTOP-U7HDUM5:1433;"
						+ "instanceName=SQLEXPRESS;"
						+ "database=People;"
						+ "integratedSecurity=true;";
				try (Connection con=DriverManager.getConnection(connURL);
						Statement stmt = con.createStatement()){
					System.out.println("Conexiune!");
					int lung = nume.length;
					if(localitate.length!=lung) {
						System.out.println("Numar incorect de parametri");
					}else {
						for (int i=0;i<lung;i++) {
							int nr = stmt.executeUpdate("update Persoane set Localitate="+
						localitate[i]+"where nume="+nume[i]);
						}
					}
				}catch (SQLException e) {
					e.printStackTrace();
				}
	}
	public static void modifLocalitate2(String[] nume, String[] localitate) throws SQLException{//cu prepared statement
		//creez stringul de conexiune
				String connURL = "jdbc:sqlserver://"
						+ "DESKTOP-U7HDUM5:1433;"
						+ "instanceName=SQLEXPRESS;"
						+ "database=People;"
						+ "integratedSecurity=true;";
				String sqlPreparat = "update Persoane set nume = ? where localitate=?";
				try (Connection con=DriverManager.getConnection(connURL);
						PreparedStatement pstmt = con.prepareStatement(sqlPreparat)){
					System.out.println("Conexiune!");
					int lung = nume.length;
					if(localitate.length!=lung) {
						System.out.println("Numar incorect de parametri");
					}else {
						for (int i=0;i<lung;i++) {
							pstmt.setString(1, nume[i]);
							pstmt.setString(2, localitate[i]);
							int nr = pstmt.executeUpdate();
							System.out.println("Nr:"+nr);
						}
					}
				}catch (SQLException e) {
					e.printStackTrace();
				}
	}
}
